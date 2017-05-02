'''
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
'''

class Solution(object):
    def _valid(self, i, j):
        for k in range(i):
            if abs(self.result[k] - j) == i - k: return False
        return True
    def _solve(self, i):
        if i == self.n:
            self.all_result.append(self.result[:])
            return
        for j in tuple(self.possible_cols):
            if self._valid(i, j):
                self.result[i] = j
                self.possible_cols.remove(j)
                self._solve(i+1)
                self.possible_cols.add(j)
    def _result2str(self):
        res = []
        for result in self.all_result:
            s = []
            for j in result: s.append('.'*j+'Q'+'.'*(self.n-j-1))
            res.append(s)
        return res
    def solveNQueens(self, n):
        self.all_result = []
        self.n = n
        self.result = [0] * n
        self.possible_cols = set(range(n))
        self._solve(0)
        return self._result2str()

if __name__ == '__main__':
    print(Solution().solveNQueens(5))


