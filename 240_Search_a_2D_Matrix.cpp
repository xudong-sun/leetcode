/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
[1,   4,  7, 11, 15],
[2,   5,  8, 12, 19],
[3,   6,  9, 16, 22],
[10, 13, 14, 17, 24],
[18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

#include "essentials.h"

#define __SOLUTION_2

#ifdef __SOLUTION_1

// binary search: O(log_4/3_(mn)), which is slower than O(m+n)

class Solution {
public:
	bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
		size_t m = matrix.size();
		if (m == 0) return false;
		size_t n = matrix[0].size();
		if (n == 0) return false;
		return searchSubMatrix(matrix, target, 0, 0, m - 1, n - 1);
	}
private:
	bool searchSubMatrix(std::vector<std::vector<int>>& matrix, int target, int x1, int y1, int x2, int y2) {
		if (x1 > x2 || y1 > y2) return false;
		int xm = (x1 + x2) / 2, ym = (y1 + y2) / 2;
		if (matrix[xm][ym] == target) return true;
		else if(matrix[xm][ym] > target)
			return searchSubMatrix(matrix, target, x1, y1, xm - 1, y2) | searchSubMatrix(matrix, target, xm, y1, x2, ym - 1);
		else return searchSubMatrix(matrix, target, xm + 1, y1, x2, y2) | searchSubMatrix(matrix, target, x1, ym + 1, xm, y2);
	}
};

#endif

#ifdef __SOLUTION_2

// O(m+n)
// start from right top corner. If it is smaller than target, delete the entire row; if it is larger than target, delete the entire column

class Solution {
public:
	bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
		size_t m = matrix.size();
		if (m == 0) return false;
		size_t n = matrix[0].size();
		if (n == 0) return false;
		int x = 0, y = n - 1;
		while (x < m && y >= 0) {
			if (matrix[x][y] == target) return true;
			else if (matrix[x][y] < target) x++;
			else y--;
		}
		return false;
	}
};

#endif

int main() {
	std::vector<std::vector<int>> matrix{ { 1, 4, 7, 11, 15 }, { 2, 5, 8, 12, 19 }, { 3, 6, 9, 16, 22 }, { 10, 13, 14, 17, 24 }, { 18, 21, 23, 26, 30 } };
	std::unordered_set<int> ansSet{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 24, 26, 30 };
	auto sol = new Solution();
	for (int i = 0; i <= 32; i++) {
		bool res = sol->searchMatrix(matrix, i);
		bool ans = ansSet.find(i) != ansSet.end();
		assert(res == ans);
	}
}