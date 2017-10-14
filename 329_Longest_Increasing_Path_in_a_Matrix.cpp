/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
[9,9,4],
[6,6,8],
[2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:
nums = [
[3,4,5],
[3,2,6],
[2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

#include "essentials.h"

class Solution {
public:
    int longestIncreasingPath(const std::vector<std::vector<int>>& matrix) {
        m = matrix.size();
        if (m == 0) return 0;
        n = matrix[0].size();
        if (n == 0) return 0;
        length.clear();
        for (int i = 0; i < m; i++) length.push_back(std::vector<int>(n, 0));
        int maxLength = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) maxLength = std::max(maxLength, maze(matrix, i, j)); 
        return maxLength;
    }
private:
    int maze(const std::vector<std::vector<int>>& matrix, int x, int y) {
        if (length[x][y] > 0) return length[x][y];
        length[x][y] = -1;
        int maxLength = 0;
        if (x > 0 && matrix[x-1][y] > matrix[x][y]) {
            if (length[x-1][y] == 0) {
                length[x-1][y] = -1;
                length[x-1][y] = maze(matrix, x-1, y);
            }
            if (length[x-1][y] > maxLength) maxLength = length[x-1][y];
        }
        if (x < m-1 && matrix[x+1][y] > matrix[x][y]) {
            if (length[x+1][y] == 0) {
                length[x+1][y] = -1;
                length[x+1][y] = maze(matrix, x+1, y);
            }
            if (length[x+1][y] > maxLength) maxLength = length[x+1][y];
        }
        if (y > 0 && matrix[x][y-1] > matrix[x][y]) {
            if (length[x][y-1] == 0) {
                length[x][y-1] = -1;
                length[x][y-1] = maze(matrix, x, y-1);
            }
            if (length[x][y-1] > maxLength) maxLength = length[x][y-1];
        }
        if (y < n-1 && matrix[x][y+1] > matrix[x][y]) {
            if (length[x][y+1] == 0) {
                length[x][y+1] = -1;
                length[x][y+1] = maze(matrix, x, y+1);
            }
            if (length[x][y+1] > maxLength) maxLength = length[x][y+1];
        }
        length[x][y] = maxLength + 1;
        return maxLength + 1;
    }
    std::vector<std::vector<int>> length;
    int m, n;
};

int main() {
    auto sol = std::make_unique<Solution>();
    assert(sol->longestIncreasingPath({{9,9,4},{6,6,8},{2,1,1}}) == 4);
    assert(sol->longestIncreasingPath({{3,4,5},{3,2,6},{2,2,1}}) == 4);
}

