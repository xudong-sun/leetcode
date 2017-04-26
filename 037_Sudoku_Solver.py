'''
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
'''

class Solution(object):
    def __init__(self):
        self.ij2grid = [[0, 0, 0, 1, 1, 1, 2, 2, 2],
                        [0, 0, 0, 1, 1, 1, 2, 2, 2],
                        [0, 0, 0, 1, 1, 1, 2, 2, 2],
                        [3, 3, 3, 4, 4, 4, 5, 5, 5],
                        [3, 3, 3, 4, 4, 4, 5, 5, 5],
                        [3, 3, 3, 4, 4, 4, 5, 5, 5],
                        [6, 6, 6, 7, 7, 7, 8, 8, 8],
                        [6, 6, 6, 7, 7, 7, 8, 8, 8],
                        [6, 6, 6, 7, 7, 7, 8, 8, 8]]
        self.grid2ij = [[(0,0), (0,1), (0,2), (1,0), (1,1), (1,2), (2,0), (2,1), (2,2)],
                        [(0,3), (0,4), (0,5), (1,3), (1,4), (1,5), (2,3), (2,4), (2,5)],
                        [(0,6), (0,7), (0,8), (1,6), (1,7), (1,8), (2,6), (2,7), (2,8)],
                        [(3,0), (3,1), (3,2), (4,0), (4,1), (4,2), (5,0), (5,1), (5,2)],
                        [(3,3), (3,4), (3,5), (4,3), (4,4), (4,5), (5,3), (5,4), (5,5)],
                        [(3,6), (3,7), (3,8), (4,6), (4,7), (4,8), (5,6), (5,7), (5,8)],
                        [(6,0), (6,1), (6,2), (7,0), (7,1), (7,2), (8,0), (8,1), (8,2)],
                        [(6,3), (6,4), (6,5), (7,3), (7,4), (7,5), (8,3), (8,4), (8,5)],
                        [(6,6), (6,7), (6,8), (7,6), (7,7), (7,8), (8,6), (8,7), (8,8)]]
    def _initialize(self):
        self.entries = []
        for _ in xrange(9):
            self.entries.append([])
            for _ in xrange(9): self.entries[-1].append({'1','2','3','4','5','6','7','8','9'})
        self.empties = []
        for i, row in enumerate(self.board):
            for j, c in enumerate(row):
                if c == '.':
                    self.empties.append([i,j])
                else:
                    for k in xrange(9):
                        if c in self.entries[i][k]: self.entries[i][k].remove(c)
                        if c in self.entries[k][j]: self.entries[k][j].remove(c)
                    g = self.ij2grid[i][j]
                    for k,l in self.grid2ij[g]:
                        if c in self.entries[k][l]: self.entries[k][l].remove(c)
    def _solve(self):
        if len(self.empties) == 0: return True
        # find the grid with minimum possible entries
        m = 10
        ij = 0
        for idx, (i,j) in enumerate(self.empties):
            if len(self.entries[i][j]) < m:
                m = len(self.entries[i][j])
                ij = idx
        if m == 0: return False
        i,j = self.empties[ij]
        self.empties.remove(self.empties[ij])
        # snapshot
        snapshot_row = []
        snapshot_col = []
        snapshot_grid = []
        for k in xrange(9):
            snapshot_row.append(set())
            for c in self.entries[i][k]: snapshot_row[k].add(c)
            snapshot_col.append(set())
            for c in self.entries[k][j]: snapshot_col[k].add(c)
        g = self.ij2grid[i][j]
        for idx,(k,l) in enumerate(self.grid2ij[g]):
            snapshot_grid.append(set())
            for c in self.entries[k][l]: snapshot_grid[idx].add(c)
        # trial
        possible_entries = set()
        for c in self.entries[i][j]: possible_entries.add(c)
        for c in possible_entries:
            self.board[i][j] = c
            for k in xrange(9):
                if c in self.entries[i][k]: self.entries[i][k].remove(c)
                if c in self.entries[k][j]: self.entries[k][j].remove(c)
            for k,l in self.grid2ij[g]:
                if c in self.entries[k][l]: self.entries[k][l].remove(c)
            if self._solve(): return True
            # recover from snapshot
            for k in xrange(9):
                self.entries[i][k] = set()
                for c in snapshot_row[k]: self.entries[i][k].add(c)
                self.entries[k][j] = set()
                for c in snapshot_col[k]: self.entries[k][j].add(c)
            for idx,(k,l) in enumerate(self.grid2ij[g]):
                self.entries[k][l] = set()
                for c in snapshot_grid[idx]: self.entries[k][l].add(c)
        self.empties.append((i,j))
        return False

    def solveSudoku(self, board):
        self.board = []
        for i in xrange(9): self.board.append([c for c in board[i]])
        self._initialize()
        self._solve()
        for i in xrange(9): board[i] = ''.join(self.board[i])

if __name__ == '__main__':
    board = ["..9748...",
             "7........",
             ".2.1.9...",
             "..7...24.",
             ".64.1.59.",
             ".98...3..",
             "...8.3.2.",
             "........6",
             "...2759.."]
    Solution().solveSudoku(board)
    print board

