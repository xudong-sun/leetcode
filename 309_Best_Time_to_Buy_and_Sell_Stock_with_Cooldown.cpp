/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/

#include "essentials.h"

class Solution {
public:
	int maxProfit(std::vector<int>& prices) {
		if (prices.size() < 2) return 0;
		int buy = -prices[0], sell = 0, cooled = 0;
		for (size_t i = 1; i < prices.size(); i++) {
			int _buy = std::max(buy, cooled - prices[i]);
			int _sell = buy + prices[i];
			int _cooled = std::max(cooled, sell);
			buy = _buy; sell = _sell; cooled = _cooled;
		}
		return std::max(sell, cooled);
	}
};

int main() {
	auto sol = std::make_unique<Solution>();
	assert(sol->maxProfit(std::vector < int > {1, 2, 3, 0, 2}) == 3);
	assert(sol->maxProfit(std::vector < int > {1, 2, 3}) == 2);
	assert(sol->maxProfit(std::vector < int > {1, 3, 2, 1, 0}) == 2);
	assert(sol->maxProfit(std::vector < int > {1}) == 0);
}