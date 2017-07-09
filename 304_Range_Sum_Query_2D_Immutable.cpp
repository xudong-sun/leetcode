/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
[3, 0, 1, 4, 2],
[5, 6, 3, 2, 1],
[1, 2, 0, 1, 5],
[4, 1, 0, 1, 7],
[1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 <= row2 and col1 <= col2.
*/

#include "essentials.h"

class NumMatrix {
public:
	NumMatrix(const std::vector<std::vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return;
		int n = matrix[0].size();
		if (n == 0) return;
		cumsum.push_back(std::vector < int > {});
		cumsum[0].push_back(matrix[0][0]);
		for (int j = 1; j < n; j++) cumsum[0].push_back(cumsum[0].back() + matrix[0][j]);
		for (int i = 1; i < m; i++) {
			cumsum.push_back(std::vector < int > {});
			cumsum.back().push_back(matrix[i][0]);
			for (int j = 1; j < n; j++) cumsum.back().push_back(cumsum.back().back() + matrix[i][j]);
			for (int j = 0; j < n; j++) cumsum[i][j] = cumsum[i][j] + cumsum[i - 1][j];
		}
	}
	int sumRegion(int row1, int col1, int row2, int col2) {
		if (row1 == 0 && col1 == 0) return cumsum[row2][col2];
		else if (row1 == 0) return cumsum[row2][col2] - cumsum[row2][col1 - 1];
		else if (col1 == 0) return cumsum[row2][col2] - cumsum[row1 - 1][col2];
		else return cumsum[row2][col2] - cumsum[row2][col1 - 1] - cumsum[row1 - 1][col2] + cumsum[row1 - 1][col1 - 1];
	}
private:
	std::vector<std::vector<int>> cumsum{};
};

int main() {
	auto sol = std::make_unique<NumMatrix>(std::vector < std::vector<int> > {{3, 0, 1, 4, 2}, { 5, 6, 3, 2, 1 }, { 1, 2, 0, 1, 5 }, { 4, 1, 0, 1, 7 }, { 1, 0, 3, 0, 5 }});
	assert(sol->sumRegion(2, 1, 4, 3) == 8);
	assert(sol->sumRegion(1, 1, 2, 2) == 11);
	assert(sol->sumRegion(1, 2, 2, 4) == 12);
}