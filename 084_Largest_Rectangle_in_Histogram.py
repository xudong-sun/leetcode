'''
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
'''


class Solution(object):
    def largestRectangleArea(self, heights):
        res = 0
        stack = []
        for i, h in enumerate(heights):
            if len(stack) == 0 or h >= stack[-1][0]:
                stack.append((h, i))
            else:
                while len(stack) > 0 and stack[-1][0] > h:
                    s = (i - stack[-1][1]) * stack[-1][0]
                    if s > res: res = s
                    w = stack.pop()
                stack.append((h, w[1]))
        l = len(heights)
        for w in stack:
            s = (l - w[1]) * w[0]
            if s > res: res = s
        return res

if __name__ == '__main__':
    print Solution().largestRectangleArea([3,4])

