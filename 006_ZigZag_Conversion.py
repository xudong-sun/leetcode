'''
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
'''

class Solution(object):
    def _getchar(self, string, pos):
        if pos < len(string): return string[pos]
        else: return ''
    def _getline(self, substring, row, total_rows):
        if row == 1: return self._getchar(substring, 0)
        elif row == total_rows: return self._getchar(substring, total_rows - 1)
        else: return self._getchar(substring, row - 1) + self._getchar(substring, 2 * total_rows - row - 1)
    def convert(self, s, numRows):
        if numRows == 1: return s
        # group s into substrings of size group_size
        group_size = 2 * (numRows - 1)
        lens = len(s)
        num_groups = (lens - 1) // group_size + 1
        ss = []
        for i in xrange(num_groups - 1):
            ss.append(s[i*group_size:(i+1)*group_size])
        ss.append(s[(num_groups-1)*group_size:])
        res = ''
        for row in xrange(1, numRows + 1):
            for i in xrange(num_groups):
                res += self._getline(ss[i], row, numRows)
        return res

if __name__ == '__main__':
    print Solution().convert('ABCDEFG', 5)


