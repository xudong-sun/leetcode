'''
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
'''

from queue import Queue
class Solution(object):
    def solve(self, board):
        m = len(board)
        if m < 3: return
        n = len(board[0])
        if n < 3: return
        mask = [[False] * n for _ in range(m)]
        q = Queue()
        for i in range(m):
            if board[i][0] == 'O' and not mask[i][0]: q.put((i, 0))
            if board[i][n-1] == 'O' and not mask[i][n-1]: q.put((i, n-1))
        for j in range(1, n-1):
            if board[0][j] == 'O' and not mask[0][j]: q.put((0, j))
            if board[m-1][j] == 'O' and not mask[m-1][j]: q.put((m-1, j))
        while q.qsize() > 0:
            x, y = q.get()
            mask[x][y] = True
            if x > 0 and board[x-1][y] == 'O' and not mask[x-1][y]: q.put((x-1, y))
            if x < m - 1 and board[x+1][y] == 'O' and not mask[x+1][y]: q.put((x+1, y))
            if y > 0 and board[x][y-1] == 'O' and not mask[x][y-1]: q.put((x, y-1))
            if y < n - 1 and board[x][y+1] == 'O' and not mask[x][y+1]: q.put((x, y+1))
        for i in range(1, m-1):
            c = ['X'] * n
            c[0] = board[i][0]
            c[-1] = board[i][-1]
            for j in range(1, n-1):
                if mask[i][j]: c[j] = 'O'
            board[i] = ''.join(c)

if __name__ == '__main__':
    board = ["XOXOXO","OXOXOX","XOXOXO","OXOXOX"]
    Solution().solve(board)
    print(board)

