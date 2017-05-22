'''
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
'''


class Solution(object):
    def partition(self, s):
        ls = len(s)
        # find all palindromes
        a = [[] for _ in xrange(ls)]
        for i in xrange(ls):
            l, r = i, i
            while l >= 0 and r < ls:
                if s[l] == s[r]: a[r].append(l)
                else: break
                l -= 1
                r += 1
            l, r = i, i+1
            while l >= 0 and r < ls:
                if s[l] == s[r]: a[r].append(l)
                else: break
                l -= 1
                r += 1
        # DFS for all solutions
        def walk(pos, result):
            if pos == -1: return [result[::-1]]
            ret = []
            for l in a[pos]: ret += walk(l-1, result + [s[l:pos+1]])
            return ret
        return walk(ls-1, [])

if __name__ == '__main__':
    print Solution().partition('aab')
    print Solution().partition('aaaaa')
    print Solution().partition('a')
    print Solution().partition('')
    print Solution().partition('abc')
    print Solution().partition('abcbab')

