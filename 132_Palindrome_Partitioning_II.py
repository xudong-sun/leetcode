'''
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
'''

# DP: O(N^2)
# a[i]: minCut for s[:i+1]

class Solution(object):
    def minCut(self, s):
        ls = len(s)
        if ls == 0: return -1
        a = [i for i in xrange(ls)] + [-1] # make a[-1] = -1
        for i in xrange(1, ls): # center of palindrome
            l, r = i, i
            while l >= 0 and r < ls:
                if s[l] == s[r]: a[r] = min(a[r], a[l-1] + 1) # a[l-1] will not change any more, since its center < i
                else: break
                l -= 1
                r += 1
            l, r = i-1, i
            while l >= 0 and r < ls:
                if s[l] == s[r]: a[r] = min(a[r], a[l-1] + 1)
                else: break
                l -= 1
                r += 1
        return a[-2]

if __name__ == '__main__':
    print Solution().minCut('aab')
    print Solution().minCut('aaaaa')
    print Solution().minCut('a')
    print Solution().minCut('')
    print Solution().minCut('abc')
    print Solution().minCut('abcbab')

