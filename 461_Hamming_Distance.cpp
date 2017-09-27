/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 <= x, y < 2^31.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/


#include "essentials.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x ^ y;
        int ans = 0;
        while (x > 0) {
            x = x & (x-1); ans++;
        }
        return ans;
    }
};

int main() {
    auto sol = std::make_unique<Solution>();
    assert(sol->hammingDistance(1, 4) == 2);
    assert(sol->hammingDistance(0, 7) == 3);
    assert(sol->hammingDistance(123, 123) == 0);
}

