'''
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
'''


class Solution(object):
    def _count(self):
        self.count = {}
        for num in self.nums:
            if num in self.count: self.count[num] += 1
            else: self.count[num] = 1
    def _permute(self, i):
        if i == self.l:
            self.result.append(self.current_result[:])
        for v in self.entries:
            if self.entries[v] < self.count[v]:
                self.entries[v] += 1
                self.current_result[i] = v
                self._permute(i + 1)
                self.entries[v] -= 1
    def permuteUnique(self, nums):
        self.nums = nums
        self.l = len(nums)
        self._count()
        self.result = []
        self.current_result = [0] * self.l
        self.entries = {v:0 for v in self.count}
        self._permute(0)
        return self.result

if __name__ == '__main__':
    print(Solution().permuteUnique([1,1,1,1,1,2]))

