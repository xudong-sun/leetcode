'''
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
'''


class Solution(object):
    def _work(self, level, cur):
        if level == self.k:
            self.all_result.append(self.result[:])
            return
        for i in xrange(cur, self.n + 1):
            self.result[level] = i
            self._work(level+1, i+1)
    def combine(self, n, k):
        self.all_result = []
        self.result = [0] * k
        self.k = k
        self.n = n
        self._work(0, 1)
        return self.all_result

if __name__ == '__main__':
    print Solution().combine(0, 0)

