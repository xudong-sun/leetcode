/*
There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 10^9 + 7.
*/


#include "essentials.h"


class Solution {
public:
  int findPaths(int m, int n, int N, int i, int j) {
    std::vector<std::vector<int>> curr(m, std::vector<int>(n, 0));
    curr[i][j] = 1;
    int total = 0;
    for (int z = 0; z < N; z++) {
      for (int p = 0; p < m; p++) {
        total = update(total, curr[p][0]);
        total = update(total, curr[p][n-1]);
      }
      for (int q = 0; q < n; q++) {
        total = update(total, curr[0][q]);
        total = update(total, curr[m-1][q]);
      }
      std::vector<std::vector<int>> prev = curr;
      curr = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
      for (int p = 0; p < m; p++) {
        for (int q = 0; q < n; q++) {
          int count = 0;
          if (p > 0) count = update(count, prev[p-1][q]);
          if (p < m-1) count = update(count, prev[p+1][q]);
          if (q > 0) count = update(count, prev[p][q-1]);
          if (q < n-1) count = update(count, prev[p][q+1]);
          curr[p][q] = count;
        }
      }
    }
    return total;
  }
private:
  int update(int x, int y) {
    return (x + y) % BIG;
  }
  const static int BIG = 1e9 + 7;
};


int main() {
  auto sol = std::unique_ptr<Solution>();
  assert(sol->findPaths(2, 2, 2, 0, 0) == 6);
  assert(sol->findPaths(1, 3, 3, 0, 1) == 12);
  assert(sol->findPaths(3, 1, 50, 2, 0) == 167772155);
  assert(sol->findPaths(1, 1, 50, 0, 0) == 4);
  assert(sol->findPaths(2, 2, 0, 0, 0) == 0);
}

