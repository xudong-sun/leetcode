/*
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:
Input: "UD"
Output: true
Example 2:
Input: "LL"
Output: false
*/


#include "essentials.h"

class Solution {
public:
  bool judgeCircle(std::string moves) {
    int x = 0, y = 0;
    for (char c : moves) {
      switch (c) {
        case 'U': x--; break;
        case 'D': x++; break;
        case 'L': y--; break;
        case 'R': y++; break;
      }
    }
    return (x == 0 && y == 0);
  }
};

int main() {
  auto sol = std::make_unique<Solution>();
  assert(sol->judgeCircle("UD") == true);
  assert(sol->judgeCircle("LL") == false);
  assert(sol->judgeCircle("UUDLDDRRUL") == true);
  assert(sol->judgeCircle("") == true);
}


