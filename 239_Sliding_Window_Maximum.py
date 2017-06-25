'''
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 <= k <= input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
'''


# Monotonic Queue: a queue (deque) where value and index of elements are both in order
# Here, q is a deque that stores indices
# For each next "num", remove all elements at back that is smaller than "num"
# In this way, elements in q is always sorted, and the maximum value in that window is q[0]
# Since each element is enqueued and dequeued once, complexity is O(n)

from collections import deque

class Solution(object):
    def maxSlidingWindow(self, nums, k):
        if not nums: return []
        q = deque()
        ans = []
        for i in xrange(k):
            num = nums[i]
            while len(q) > 0 and num >= nums[q[-1]]: q.pop()
            q.append(i)
        ans.append(nums[q[0]])
        for i in xrange(k, len(nums)):
            if q[0] == i - k: q.popleft()
            num = nums[i]
            while len(q) > 0 and num >= nums[q[-1]]: q.pop()
            q.append(i)
            ans.append(nums[q[0]])
        return ans

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3), [3,3,5,5,6,7])
    def test2(self):
        self.assertEqual(Solution().maxSlidingWindow([1,2,3,4,5,4,3,2,1], 3), [3,4,5,5,5,4,3])
    def test3(self):
        self.assertEqual(Solution().maxSlidingWindow([3,6,4,-1,2], 5), [6])
    def test4(self):
        self.assertEqual(Solution().maxSlidingWindow([3,6,4,-1,2], 1), [3,6,4,-1,2])
    def test5(self):
        self.assertEqual(Solution().maxSlidingWindow([], 0), [])

if __name__ == '__main__':
    unittest.main()

