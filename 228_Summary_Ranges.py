'''
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
'''


class Solution(object):
    def summaryRanges(self, nums):
        if len(nums) == 0: return []
        elif len(nums) == 1: return [str(nums[0])]
        ranges = []
        start = nums[0]
        for i, num in enumerate(nums[1:]):
            if num - nums[i] != 1:
                ranges.append((start, nums[i]))
                start = num
        ranges.append((start, num))
        return [str(r[0]) if r[0] == r[1] else '->'.join(map(str, r)) for r in ranges]

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().summaryRanges([0,1,2,4,5,7]), ['0->2', '4->5', '7'])
    def test2(self):
        self.assertEqual(Solution().summaryRanges([-10,-5,-4,-1,0,1,2,3,4]), ['-10', '-5->-4', '-1->4'])
    def test3(self):
        self.assertEqual(Solution().summaryRanges([-1]), ['-1'])
    def test4(self):
        self.assertEqual(Solution().summaryRanges([]), [])

if __name__ == '__main__':
    unittest.main()

