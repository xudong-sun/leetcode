'''
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
'''

# Hint: two pointers

class Solution(object):
    def maxArea(self, height):
        x, y = 0, len(height) - 1
        area = lambda x, y: min(height[x], height[y]) * (y - x)
        def next_x(x, y):
            xx = x
            while xx < y and height[xx] <= height[x]: xx += 1
            return xx
        def next_y(x, y):
            yy = y
            while yy > x and height[yy] <= height[y]: yy -= 1
            return yy
        max_area = 0
        while x < y:
            max_area = max(max_area, area(x, y))
            if height[x] < height[y]: x = next_x(x, y)
            else: y = next_y(x, y)
        return max_area

if __name__ == '__main__':
    print Solution().maxArea([1, 2, 3, 2, 5, 3, 5, 3, 10, 1, 10, 1])


