'''
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 <= k <= array's length.
'''


'''
# partition
class Solution(object):
    def findKthLargest(self, nums, k):
        def partition(l, r):
            tmp = nums[l]
            x, y = l, r
            while True:
                while x < y and nums[y] < tmp: y -= 1
                if x == y: break
                nums[x] = nums[y]
                x += 1
                while x < y and nums[x] > tmp: x += 1
                if x == y: break
                nums[y] = nums[x]
                y -= 1
            nums[x] = tmp
            return x
        l, r, k = 0, len(nums)-1, k-1
        while True:
            x = partition(l, r)
            if x == k: return nums[k]
            elif x < k: l = x + 1
            else: r = x - 1
        assert False
'''

# heap sort
import heapq
class Solution(object):
    def findKthLargest(self, nums, k):
        return heapq.nlargest(k, nums)[-1]

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().findKthLargest([3,2,1,5,6,4], 2), 5)
        self.assertEqual(Solution().findKthLargest([3,2,1,5,6,4], 1), 6)
        self.assertEqual(Solution().findKthLargest([3,2,1,5,6,4], 6), 1)
    def test2(self):
        import random
        for _ in xrange(100):
            n = random.randint(1, 100)
            l = [random.randint(1, 10000) for _ in xrange(n)]
            k = random.randint(1, n)
            ans = sorted(l, reverse=True)[k-1]
            self.assertEqual(Solution().findKthLargest(l, k), ans)

if __name__ == '__main__':
    unittest.main()

