/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/

#include "essentials.h"

class Solution {
public:
  std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& matrix) {
    if (matrix.size() == 0) return {};
    size_t m = matrix.size(), n = matrix[0].size();
    std::vector<std::vector<int>> result(m, std::vector<int>(n, -1));
    std::deque<std::pair<int, int>> queue;
    for (size_t i = 0; i < m; i++)
      for (size_t j = 0; j < n; j++)
        if (matrix[i][j] == 0) {
          result[i][j] = 0;
          queue.push_back({i,j});
        }
    while (queue.size() > 0) {
      auto p = queue.front();
      queue.pop_front();
      int x = p.first, y = p.second;
      if (x > 0 && result[x-1][y] == -1) {
        result[x-1][y] = result[x][y] + 1;
        queue.push_back({x-1, y});
      }
      if (x < m-1 && result[x+1][y] == -1) {
        result[x+1][y] = result[x][y] + 1;
        queue.push_back({x+1, y});
      }
      if (y > 0 && result[x][y-1] == -1) {
        result[x][y-1] = result[x][y] + 1;
        queue.push_back({x, y-1});
      }
      if (y < n-1 && result[x][y+1] == -1) {
        result[x][y+1] = result[x][y] + 1;
        queue.push_back({x, y+1});
      }
    }
    return result;
  }
};

int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<std::vector<int>> matrix = {{0,0,0},{0,1,0},{0,0,0}};
  std::vector<std::vector<int>> answer = {{0,0,0},{0,1,0},{0,0,0}};
  assert(sol->updateMatrix(matrix) == answer);
  matrix = {{0,0,0},{0,1,0},{1,1,1}};
  answer = {{0,0,0},{0,1,0},{1,2,1}};
  assert(sol->updateMatrix(matrix) == answer);
}


