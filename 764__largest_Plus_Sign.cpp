/*
In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except those cells in the given list mines which are 0. What is the largest axis-aligned plus sign of 1s contained in the grid? Return the order of the plus sign. If there is none, return 0.

An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along with 4 arms of length k-1 going up, down, left, and right, and made of 1s. This is demonstrated in the diagrams below. Note that there could be 0s or 1s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1s.

Examples of Axis-Aligned Plus Signs of Order k:

Order 1:
000
010
000

Order 2:
00000
00100
01110
00100
00000

Order 3:
0000000
0001000
0001000
0111110
0001000
0001000
0000000
Example 1:

Input: N = 5, mines = [[4, 2]]
Output: 2
Explanation:
11111
11111
11111
11111
11011
In the above grid, the largest plus sign can only be order 2.  One of them is marked in bold.
Example 2:

Input: N = 2, mines = []
Output: 1
Explanation:
There is no plus sign of order 2, but there is of order 1.
Example 3:

Input: N = 1, mines = [[0, 0]]
Output: 0
Explanation:
There is no plus sign, so return 0.
Note:

N will be an integer in the range [1, 500].
mines will have length at most 5000.
mines[i] will be length 2 and consist of integers in the range [0, N-1].
(Additionally, programs submitted in C, C++, or C# will be judged with a slightly smaller time limit.)
*/

#include "essentials.h"

class Solution {
public:
  int orderOfLargestPlusSign(int N, std::vector<std::vector<int>>& mines) {
    // build map
    std::vector<std::vector<int>> map(N, std::vector<int>(N, 1));
    for (auto p : mines) {
      map[p[0]][p[1]] = 0;
    }
    // find consecutive 1's
    std::vector<std::vector<int>> left(N, std::vector<int>(N, 0));
    std::vector<std::vector<int>> right(N, std::vector<int>(N, 0));
    std::vector<std::vector<int>> up(N, std::vector<int>(N, 0));
    std::vector<std::vector<int>> down(N, std::vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
      left[i][0] = map[i][0];
      for (int j = 1; j < N; j++) {
        if (map[i][j] == 0) left[i][j] = 0;
        else left[i][j] = left[i][j-1] + 1;
      }
      right[i][N-1] = map[i][N-1];
      for (int j = N-2; j >= 0; j--) {
        if (map[i][j] == 0) right[i][j] = 0;
        else right[i][j] = right[i][j+1] + 1;
      }
    }
    for (int j = 0; j < N; j++) {
      up[0][j] = map[0][j];
      for (int i = 1; i < N; i++) {
        if (map[i][j] == 0) up[i][j] = 0;
        else up[i][j] = up[i-1][j] + 1;
      }
      down[N-1][j] = map[N-1][j];
      for (int i = N-2; i >= 0; i--) {
        if (map[i][j] == 0) down[i][j] = 0;
        else down[i][j] = down[i+1][j] + 1;
      }
    }
    // find the largest order
    int order = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        order = std::max(std::min({left[i][j], right[i][j], up[i][j], down[i][j]}), order);
      }
    }
    return order;
  }
};


int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<std::vector<int>> mines = {{4,2}};
  assert(sol->orderOfLargestPlusSign(5, mines) == 2);
  mines = {};
  assert(sol->orderOfLargestPlusSign(2, mines) == 1);
  mines = {{0,0}};
  assert(sol->orderOfLargestPlusSign(1, mines) == 0);
}


