'''
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
'''

# Solution 1: O(N), but complicated
class Solution(object):
    def isValid(self, s):
        map_open_style = {'(': 0, '[': 1, '{': 2}
        map_close_style = {')': 0, ']': 1, '}': 2}
        cnt = []
        style = []
        for ch in s:
            if ch in map_open_style:
                cnt.append(1)
                style.append(map_open_style[ch])
            elif ch in map_close_style:
                if len(style) > 0 and style[-1] == map_close_style[ch]:
                    cnt[-1] -= 1
                    if cnt[-1] == 0:
                        cnt.pop()
                        style.pop()
                else: return False
        return len(style) == 0

# Solution 2: O(N) use a stack
class Solution(object):
    def isValid(self, s):
        stack = []
        mappings = {')': '(', ']': '[', '}': '{'}
        for ch in s:
            if ch in '([{': stack.append(ch)
            else:
                if len(stack) == 0 or stack[-1] != mappings[ch]: return False
                stack.pop()
        return len(stack) == 0

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertTrue(Solution().isValid('((()))'))
    def test2(self):
        self.assertFalse(Solution().isValid('([(()]))'))
    def test3(self):
        self.assertFalse(Solution().isValid('((())'))
    def test4(self):
        self.assertFalse(Solution().isValid(')('))
    def test5(self):
        self.assertTrue(Solution().isValid(''))

if __name__ == '__main__':
    unittest.main()
