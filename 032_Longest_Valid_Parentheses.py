'''
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
'''

'''
# Solution 1: DP O(n), 72ms
# a[i] is the longest valid parentheses ending with s[i]
# for each ')'
# 1. if the previous is '(', then a[i] = a[i-2] + 2
# 2. else, goto position p=i-a[i-1]-1, if it is '(', then a[i] = a[i-1] + a[p-1] + 2
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
'''
'''
# Solution 2: use a stack, O(n), 59ms
# The items in the stack are all '('s, each one assigned a value
# Its meaning: the extra length to `value_top` if this '(' is paired with another ')'
# The stack itself has a value `value_top` at the top, initialized to 0
# `value_top` is the maximum length of valid parentheses ending at the current scan point
# scan s, if s[i] is '(': push it to stack with value `value_top`, assign `value_top=0`
# if s[i] is ')':
# 1. pop(), assign `value_top = value_of_this_( + value_top + 2`
# 2. if cannot pop(), assign `value_top=0`
class Solution(object):
    def longestValidParentheses(self, s):
        stack, value, res = [], 0, 0
        for ch in s:
            if ch == '(':
                stack.append(value)
                value = 0
            elif len(stack) > 0:
                value += stack.pop() + 2
                res = max(res, value)
            else:
                value = 0
        return res
'''

# Solution 3: O(n), 89ms
# first scan forward, then scan backward
class Solution(object):
    def longestValidParentheses(self, s):
        z, l, res = 0, 0, 0
        # forward
        for ch in s:
            if ch == '(': z += 1
            else: z -= 1
            if z >= 0: l += 1
            else: l, z = 0, 0
            if z == 0: res = max(l, res)
        # backward
        z, l = 0, 0
        for ch in s[::-1]:
            if ch == ')': z += 1
            else: z -= 1
            if z >= 0: l += 1
            else: l, z = 0, 0
            if z == 0: res = max(l, res)
        return res

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().longestValidParentheses('(()'), 2)
    def test2(self):
        self.assertEqual(Solution().longestValidParentheses(')()())'), 4)
    def test3(self):
        self.assertEqual(Solution().longestValidParentheses('()'), 2)
    def test4(self):
        self.assertEqual(Solution().longestValidParentheses('))))('), 0)
    def test5(self):
        self.assertEqual(Solution().longestValidParentheses(')(()()())()(('), 10)
    def test6(self):
        self.assertEqual(Solution().longestValidParentheses(''), 0)

if __name__ == '__main__':
    unittest.main()
