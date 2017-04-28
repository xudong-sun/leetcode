'''
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
'''

class Solution(object):
    def isMatch(self, s, p):
        l = len(s)
        m = [False] * (l+1)
        m[0] = True
        for ch in p:
            if ch == '?':
                for i in range(l, 0, -1):
                    m[i] = m[i-1]
                m[0] = False
            elif ch == '*':
                for i in range(l+1):
                    if m[i]: break
                for j in range(i+1, l+1): m[j] = True
            else:
                for i in range(l, 0, -1):
                    m[i] = m[i-1] and s[i-1] == ch
                m[0] = False
            if not any(m): return False
        return m[-1]

if __name__ == '__main__':
    print(Solution().isMatch('', ''))


