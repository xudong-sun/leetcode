'''
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
'''

class Solution(object):
    def longestValidParentheses(self, s):
        s = ')' + s
        l = len(s)
        if l < 3: return 0
        a = [0] * l
        res = 0
        for i, c in enumerate(s[2:]):
            i += 2
            if c == ')':
                if s[i-1] == '(':
                    a[i] = a[i-2] + 2
                    if a[i] > res: res = a[i]
                else:
                    p = i - a[i-1] - 1
                    if s[p] == '(':
                        a[i] = a[i-1] + a[p-1] + 2
                        if a[i] > res: res = a[i]
        return res

if __name__ == '__main__':
    print Solution().longestValidParentheses('()')

