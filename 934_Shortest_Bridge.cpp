/*
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.



Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1


Constraints:

n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.
There are exactly two islands in grid.
*/


#include "essentials.h"

class Solution {
public:
  int shortestBridge(const std::vector<std::vector<int>>& A) {
    int n = A.size();
    std::queue<std::pair<int, int>> q1;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
      bool found = false;
      for (int j = 0; j < n; j++) {
        if (A[i][j] == 1) {
          found = true;
          q1.push({i, j});
          visited[i][j] = true;
          break;
        }
      }
      if (found) break;
    }
    std::queue<std::pair<int, int>> q2;
    while (!q1.empty()) {
      auto p = q1.front();
      int x = p.first, y = p.second;
      q1.pop();
      q2.push(p);
      if (x > 0 && A[x-1][y] == 1 && visited[x-1][y] == false) {
        q1.push({x-1, y});
        visited[x-1][y] = true;
      }
      if (x < n - 1 && A[x+1][y] == 1 && visited[x+1][y] == false) {
        q1.push({x+1, y});
        visited[x+1][y] = true;
      }
      if (y > 0 && A[x][y-1] == 1 && visited[x][y-1] == false) {
        q1.push({x, y-1});
        visited[x][y-1] = true;
      }
      if (y < n - 1 && A[x][y+1] == 1 && visited[x][y+1] == false) {
        q1.push({x, y+1});
        visited[x][y+1] = true;
      }
    }
    int ans = 0;
    while (!q2.empty()) {
      std::queue<std::pair<int, int>> q;
      while (!q2.empty()) {
        auto p = q2.front();
        int x = p.first, y = p.second;
        q2.pop();
        if (ans > 0 && A[x][y] == 1) return ans - 1;
        if (x > 0 && visited[x-1][y] == false) {
          q.push({x-1, y});
          visited[x-1][y] = true;
        }
        if (x < n - 1 && visited[x+1][y] == false) {
          q.push({x+1, y});
          visited[x+1][y] = true;
        }
        if (y > 0 && visited[x][y-1] == false) {
          q.push({x, y-1});
          visited[x][y-1] = true;
        }
        if (y < n - 1 && visited[x][y+1] == false) {
          q.push({x, y+1});
          visited[x][y+1] = true;
        }
      }
      ans++;
      q2 = std::move(q);
    }
    return -1;
  }
};


int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<std::vector<int>> A = {{0,1},{1,0}};
  assert(sol->shortestBridge(A) == 1);
  A = {{0,1,0},{0,0,0},{0,0,1}};
  assert(sol->shortestBridge(A) == 2);
  A = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
  assert(sol->shortestBridge(A) == 1);
}

