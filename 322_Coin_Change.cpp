/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/

#include "essentials.h"

class Solution {
public:
    int coinChange(const std::vector<int>& coins, int amount) {
        std::vector<int> result;
        result.push_back(0);
        for (int x = 1; x <= amount; x++) {
            int count = INT_MAX - 1;
            for (auto coin : coins) {
                if (coin <= x) count = std::min(count, result[x-coin]);
            }
            result.push_back(std::min(count + 1, INT_MAX));
        }
        return result.back() == INT_MAX ? -1 : result.back();
    }
};

int main(int argc, char *argv[])
{
    auto sol = std::make_unique<Solution>();
    assert(sol->coinChange(std::vector<int>{1,2,5}, 11) == 3);
    assert(sol->coinChange(std::vector<int>{2}, 3) == -1);
    assert(sol->coinChange(std::vector<int>{1,3,10}, 18) == 5);
    assert(sol->coinChange(std::vector<int>{1}, 1000000) == 1000000);
    return 0;
}
