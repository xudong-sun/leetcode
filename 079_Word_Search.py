'''
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
'''


class Solution(object):
    def _find(self, level, x, y):
        if level == len(self.word):
            self.found = True
            return
        if x > 0 and not self.visited[x-1][y] and self.board[x-1][y] == self.word[level]:
            self.visited[x-1][y] = True
            self._find(level+1, x-1, y)
            self.visited[x-1][y] = False
        if self.found: return
        if x < self.m - 1 and not self.visited[x+1][y] and self.board[x+1][y] == self.word[level]:
            self.visited[x+1][y] = True
            self._find(level+1, x+1, y)
            self.visited[x+1][y] = False
        if self.found: return
        if y > 0 and not self.visited[x][y-1] and self.board[x][y-1] == self.word[level]:
            self.visited[x][y-1] = True
            self._find(level+1, x, y-1)
            self.visited[x][y-1] = False
        if self.found: return
        if y < self.n -1 and not self.visited[x][y+1] and self.board[x][y+1] == self.word[level]:
            self.visited[x][y+1] = True
            self._find(level+1, x, y+1)
            self.visited[x][y+1] = False
    def exist(self, board, word):
        if len(word) == 0: return True
        self.word = word
        self.board = board
        self.m = len(board)
        if self.m == 0: return False
        self.n = len(board[0])
        if self.n == 0: return False
        self.found = False
        self.visited = [[False] * self.n for _ in xrange(self.m)]
        for i in xrange(self.m):
            for j in xrange(self.n):
                if board[i][j] == word[0]: 
                    self.visited[i][j] = True
                    self._find(1, i, j)
                    self.visited[i][j] = False
                if self.found: return True
        return self.found

if __name__ == '__main__':
    #print Solution().exist(['abce','sfcs','adee'], 'q')
    print Solution().exist(['aa'], 'aaa')

