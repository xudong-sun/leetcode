'''
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
'''

class Solution(object):
    def trap(self, height):
        l = len(height)
        if l == 0: return 0
        h = [0] * l
        h[-1] = height[-1]
        for i in xrange(l-2, -1, -1):
            h[i] = max(h[i+1], height[i])
        m = height[0]
        s = 0
        for i in xrange(1, l):
            x = min(m, h[i])
            if height[i] < x: s += x - height[i]
            if height[i] > m: m = height[i]
        return s

if __name__ == '__main__':
    print Solution().trap([1,2,2,1])

