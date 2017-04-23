'''
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
'''

# WA
class Solution(object):
    def strStr(self, haystack, needle):
        if len(needle) == 0: return 0
        # parse needle
        l = len(needle)
        p = [0] * l
        for i in xrange(1, l):
            if needle[p[i-1]] == needle[i]: p[i] = p[i-1] + 1
            elif needle[i] == needle[0]: p[i] = 1
            else: p[i] = 0
        # match
        i = j = k = 0
        ll = len(haystack)
        while j < ll:
            if haystack[j] == needle[k]:
                j += 1
                k += 1
            else:
                if k > 0:
                    i = j - p[k - 1]
                    k = p[k - 1]
                else:
                    i += 1
                    j += 1
            if k == l: return i
        return -1

if __name__ == '__main__':
    print Solution().strStr('aaaaab', 'aab')

