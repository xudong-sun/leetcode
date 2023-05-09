/*
Your music player contains n different songs. You want to listen to goal songs (not necessarily different) during your trip. To avoid boredom, you will create a playlist so that:

Every song is played at least once.
A song can only be played again only if k other songs have been played.
Given n, goal, and k, return the number of possible playlists that you can create. Since the answer can be very large, return it modulo 109 + 7.



Example 1:

Input: n = 3, goal = 3, k = 1
Output: 6
Explanation: There are 6 possible playlists: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and [3, 2, 1].
Example 2:

Input: n = 2, goal = 3, k = 0
Output: 6
Explanation: There are 6 possible playlists: [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], and [1, 2, 2].
Example 3:

Input: n = 2, goal = 3, k = 1
Output: 2
Explanation: There are 2 possible playlists: [1, 2, 1] and [2, 1, 2].
*/


#include "essentials.h"

class Solution {
public:
  int numMusicPlaylists(int n, int goal, int k) {
    std::vector<std::vector<int>> a(101, std::vector<int>(101, 0));
    a[1][1] = 1;
    for (int i = 2; i <= goal; i++) {
      for (int j = 1; j <= std::min(i, n); j++) {
        a[i][j] = Add(Mul(a[i-1][j], std::max(j-k, 0)), a[i-1][j-1]);
      }
    }
    int ans = a[goal][n];
    for (int i = 2; i <= n; i++) {
      ans = Mul(ans, i);
    }
    return ans;
  }
private:
  int Mul(int64_t x, int64_t y) {
    int64_t ans = x * y;
    return ans % modulo;
  }
  int Add(int x, int y) {
    return (x + y) % modulo;
  }
  int modulo = 1000000007;
};


int main() {
  auto sol = std::make_unique<Solution>();
  assert(sol->numMusicPlaylists(3, 3, 1) == 6);
  assert(sol->numMusicPlaylists(2, 3, 0) == 6);
  assert(sol->numMusicPlaylists(2, 3, 1) == 2);
}

