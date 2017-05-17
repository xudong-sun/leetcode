'''
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
'''


class Solution(object):
    def maxProfit(self, k, prices):
        if k == 0: return 0
        l = len(prices)
        # quick solve: we can do always do a transaction
        if l <= k*2:
            ans = 0
            for i in xrange(l-1): ans += max(prices[i+1] - prices[i], 0)
            return ans
        buy = [-0x80000000] * k # buy[i]: the maximum money when we just buy for the (i+1)-th transaction
        sell = [0] * k          # sell[i]: the maximum money when we just sell for the (i+1)-th transaction
        for i in xrange(l): # for each time i
            for j in xrange(k-1, 0, -1):
                sell[j] = max(sell[j], buy[j] + prices[i]) # do nothing, or sell for the (j+1)-th transaction, at time i
                buy[j] = max(buy[j], sell[j-1] - prices[i]) # do nothing, or buy for the (j+1)-th transaction, at time i
            sell[0] = max(sell[0], buy[0] + prices[i])
            buy[0] = max(buy[0], -prices[i])
        return sell[-1] # sell is initialized with all 0, i.e. if you conduct i transactions, the profit is initialized 0. therefore we return sell[-1] instead of max(sell)

if __name__ == '__main__':
    print Solution().maxProfit(2, [7,1,5,3,6,4])
    print Solution().maxProfit(5, [7,6,4,3,1])
    print Solution().maxProfit(2, [5])
    print Solution().maxProfit(0, [7,3,4,2,8,1,4,2,6])
    print Solution().maxProfit(1, [7,3,4,2,8,1,4,2,6])
    print Solution().maxProfit(2, [7,3,4,2,8,1,4,2,6])
    print Solution().maxProfit(3, [7,3,4,2,8,1,4,2,6])
    print Solution().maxProfit(4, [7,3,4,2,8,1,4,2,6])
    print Solution().maxProfit(2, [1,2])
    print Solution().maxProfit(2, [1,2,3])
    print Solution().maxProfit(2, [1,3,2])

