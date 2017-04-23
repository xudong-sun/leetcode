'''
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
'''

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

if __name__ == '__main__':
    print Solution().isValid('([(()]))')

