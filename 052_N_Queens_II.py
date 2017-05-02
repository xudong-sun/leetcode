'''
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
'''

class Solution(object):
    def _valid(self, i, j):
        for k in range(i):
            if abs(self.result[k] - j) == i - k: return False
        return True
    def _solve(self, i):
        if i == self.n:
            self.count += 1
            return
        for j in tuple(self.possible_cols):
            if self._valid(i, j):
                self.result[i] = j
                self.possible_cols.remove(j)
                self._solve(i+1)
                self.possible_cols.add(j)
    def totalNQueens(self, n):
        self.count = 0
        self.n = n
        self.result = [0] * n
        self.possible_cols = set(range(n))
        self._solve(0)
        return self.count

if __name__ == '__main__':
    print(Solution().solveNQueens(8))


