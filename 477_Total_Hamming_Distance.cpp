/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.
*/


#include "essentials.h"

class Solution {
public:
    int totalHammingDistance(const std::vector<int>& nums) {
        int ans = 0;
        std::array<int, 32> bitCount{0};
        for (size_t i = 0; i < nums.size(); i++) {
            for (int pos = 0, z = 1; pos < 32; pos++, z <<= 1) {
                if ((nums[i] & z) > 0) ans += i - (bitCount[pos]++);
                else ans += bitCount[pos];
            }
        }
        return ans;
    }
};

int main() {
    auto sol = std::make_unique<Solution>();
    assert(sol->totalHammingDistance(std::vector<int>{4,14,2}) == 6);
    assert(sol->totalHammingDistance(std::vector<int>{123,123,123,123}) == 0);
    assert(sol->totalHammingDistance(std::vector<int>{1,2,3,4,5,6,7,8,9,10}) == 95);
}
