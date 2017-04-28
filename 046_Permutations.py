'''
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
'''


class Solution(object):
    def _get_permutation(self, i):
        if len(self.entries) == 0:
            self.result.append(self.current_result[:])
        for idx in self.entries:
            self.entries.remove(idx)
            self.current_result[i] = self.nums[idx]
            self._get_permutation(i + 1)
            self.entries.add(idx)
    def permute(self, nums):
        self.nums = nums
        l = len(nums)
        self.entries = set(range(l))
        self.result = []
        self.current_result = [0] * l
        self._get_permutation(0)
        return self.result

if __name__ == '__main__':
    print(Solution().permute([]))

