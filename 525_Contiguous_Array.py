"""
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
"""

class Solution(object):
    def findMaxLength(self, nums):
        count = 0
        res = 0
        mapping = {0: -1}
        for i, num in enumerate(nums):
            count += 1 if num == 1 else -1
            if count in mapping: res = max(res, i-mapping[count])
            else: mapping[count] = i
        return res

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().findMaxLength([0,1]), 2)
    def test2(self):
        self.assertEqual(Solution().findMaxLength([0,1,0]), 2)
    def test3(self):
        self.assertEqual(Solution().findMaxLength([0,0,0,0,1,1]), 4)
    def test4(self):
        self.assertEqual(Solution().findMaxLength([0,0,0]), 0)

if __name__ == "__main__":
    unittest.main()


