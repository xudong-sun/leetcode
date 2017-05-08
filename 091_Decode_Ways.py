'''
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
'''


class Solution(object):
    def numDecodings(self, s):
        l = len(s)
        if l == 0: return 0
        a = [0] * (l+1)
        if s[0] == '0': return 0
        a[0] = a[1] = 1
        for i in xrange(1, l):
            if s[i] != '0': a[i+1] += a[i]
            if s[i-1] == '1' or (s[i-1] == '2' and s[i] in '0123456'): a[i+1] += a[i-1]
            if a[i+1] == 0: return 0
        return a[l]

if __name__ == '__main__':
    print Solution().numDecodings('102030')


