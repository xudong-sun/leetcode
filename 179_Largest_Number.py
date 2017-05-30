'''
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
'''


class Solution:
    def largestNumber(self, nums):
        if all([v == 0 for v in nums]): return '0'
        nums = [str(v) for v in nums]
        l = max([len(s) for s in nums]) * 2
        for i in xrange(len(nums)):
            key = nums[i]
            while len(key) < l: key = key + nums[i]
            nums[i] = nums[i], key
        nums.sort(key=lambda x: x[1], reverse=True)
        return ''.join([s[0] for s in nums])

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().largestNumber([3,30,34,5,9]), '9534330')
    def test2(self):
        self.assertEqual(Solution().largestNumber([3,30,31,32,33,34,302,331,334]), '34334333331323130302')
    def test3(self):
        self.assertEqual(Solution().largestNumber([0,10,3,103]), '3103100')
    def test4(self):
        self.assertEqual(Solution().largestNumber([]), '0')
    def test5(self):
        self.assertEqual(Solution().largestNumber([0,0]), '0')
    def test6(self):
        self.assertEqual(Solution().largestNumber([1212,121,12,1]), '1212121211')

if __name__ == '__main__':
    unittest.main()

