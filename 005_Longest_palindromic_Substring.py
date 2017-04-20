'''
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
'''


'''
# O(n^2) solution
class Solution(object):
    def longestPalindrome(self, s):
        l = len(s)
        max_length, left, right = 1, 0, 0
        for i in xrange(l - 1):
            z = 1
            while i - z >= 0 and i + z < l and s[i - z] == s[i + z]: z += 1
            if 2 * z - 1 > max_length:
                max_length = 2 * z - 1
                left = i - z + 1
                right = i + z - 1
            if s[i] == s[i + 1]:
                z = 1
                while i - z >= 0 and i + 1 + z < l and s[i - z] == s[i + 1 + z]: z += 1
                if 2 * z > max_length:
                    max_length = 2 * z
                    left = i - z + 1
                    right = i + z
        return s[left:right+1]
'''

# Manacher's algorithm: O(n)
class Solution(object):
    def longestPalindrome(self, s):
        center = 0
        lens = len(s)
        ix = mx = 0
        c = [0] * (2 * lens - 1)
        maxc, maxcp = 0, 0
        while center <= lens - 1:
            p = int(center * 2)
            if center < mx:
                j = 2 * ix - center
                c[p] = min(c[int(j * 2)], mx - center)
            else: c[p] = int(center) - center
            c[p] += 1
            while center - c[p] >= 0 and center + c[p] < lens and s[int(center - c[p])] == s[int(center + c[p])]: c[p] += 1
            c[p] -= 1
            if center + c[p] > mx:
                ix = center
                mx = center + c[p]
            if c[p] > maxc:
                maxc = c[p]
                maxcp = center
            center += 0.5
        return s[int(maxcp - maxc) : int(maxcp + maxc) + 1]

if __name__ == '__main__':
    print Solution().longestPalindrome('abccbab')

