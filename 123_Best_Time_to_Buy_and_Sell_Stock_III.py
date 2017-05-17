'''
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
'''


class Solution(object):
    def maxProfit(self, prices):
        l = len(prices)
        if l < 2: return 0
        elif l == 2: return max(prices[1] - prices[0], 0)
        m = prices[0]
        first = [0] * l
        for i in xrange(1, l):
            first[i] = max(first[i-1], prices[i] - m)
            m = min(m, prices[i])
        m = prices[-1]
        second = [0] * l
        for i in xrange(l-2, -1, -1):
            second[i] = max(second[i+1], m - prices[i])
            m = max(m, prices[i])
        ans = 0
        for i in xrange(1, l-1): ans = max(ans, first[i] + second[i])
        return ans

if __name__ == '__main__':
    print Solution().maxProfit([7,1,5,3,6,4])
    print Solution().maxProfit([7,6,4,3,1])
    print Solution().maxProfit([5])
    print Solution().maxProfit([7,3,4,2,8,1,4,2,6])
    print Solution().maxProfit([1,2])
    print Solution().maxProfit([1,2,3])
    print Solution().maxProfit([1,3,2])

