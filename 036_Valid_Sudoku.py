'''
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'
Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
'''

class Solution(object):
    def isValidSudoku(self, board):
        rows = []
        cols = []
        grids = []
        valid_chars = '123456789.'
        for _ in xrange(9):
            rows.append(set())
            cols.append(set())
            grids.append(set())
        for i, row in enumerate(board):
            for j, c in enumerate(row):
                if c not in valid_chars: return False
                if c == '.': continue
                if c in rows[i] or c in cols[j]: return False
                g = (i / 3) * 3 + (j / 3)
                if c in grids[g]: return False
                rows[i].add(c)
                cols[j].add(c)
                grids[g].add(c)
        return True

if __name__ == '__main__':
    print Solution().isValidSudoku([".87654321",
                                    "2........",
                                    "3........",
                                    "4........",
                                    "5........",
                                    "6........",
                                    "7........",
                                    "8........",
                                    "9........"])

