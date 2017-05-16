'''
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
'''


# DP: a[j]: bool, s3[:i] is interleave of s1[:j] and s2[:i-j]
# O(mn), m=len(s3), n=len(s1)
class Solution(object):
    def isInterleave(self, s1, s2, s3):
        l1, l2, l3 = len(s1), len(s2), len(s3)
        if l3 != l1 + l2: return False
        if l1 > l2:
            s1, s2 = s2, s1
            l1, l2 = l2, l1
        a = [True] + [False] * l1
        for i in xrange(1, l3+1):
            for j in xrange(min(i, l1), -1, -1):
                a[j] = (0 <= j-1 < l1 and a[j-1] and s1[j-1] == s3[i-1]) or (0 <= i-j-1 < l2 and a[j] and s2[i-j-1] == s3[i-1])
            if not any(a): return False
        return True

if __name__ == '__main__':
    print Solution().isInterleave('aabcc', 'dbbca', 'aadbbcbcac')
    print Solution().isInterleave('aabcc', 'dbbca', 'aadbbbaccc')
    print Solution().isInterleave('ab', '', 'ab')
    print Solution().isInterleave('', 'ab', 'ab')
    print Solution().isInterleave('a', 'a', 'aa')
    print Solution().isInterleave('', '', '')

