'''
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
'''

class Solution(object):
    def _get_string(self, string, open_cnt, close_cnt):
        if open_cnt == close_cnt == self.total_cnt: self.result.append(string)
        if open_cnt < self.total_cnt: self._get_string(string + '(', open_cnt + 1, close_cnt)
        if close_cnt < open_cnt: self._get_string(string + ')', open_cnt, close_cnt + 1)
    def generateParenthesis(self, n):
        self.total_cnt = n
        self.result = []
        self._get_string('', 0, 0)
        return self.result

if __name__ == '__main__':
    print Solution().generateParenthesis(4)

