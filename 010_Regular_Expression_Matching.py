'''
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") false
isMatch("aa","aa") true
isMatch("aaa","aa") false
isMatch("aa", "a*") true
isMatch("aa", ".*") true
isMatch("ab", ".*") true
isMatch("aab", "c*a*b") true
'''

class Solution(object):
    def isMatch(self, s, p):
        lens = len(s)
        match = [True] + [False] * lens
        def parse_pattern(p):
            lenp = len(p)
            i = 0
            while (i < lenp):
                ch = p[i]
                if i < lenp - 1 and p[i + 1] == '*': multiple = True
                else: multiple = False
                yield ch, multiple
                i += 1 + multiple
        for ch, multiple in parse_pattern(p):
            match_ = [False] * (lens + 1)
            if not multiple:
                for i in xrange(lens):
                    if match[i] == True: # last match
                        if ch == '.' or ch == s[i]: match_[i + 1] = True
            else:
                i = 0
                while i < lens + 1:
                    if match[i] == True:
                        match_[i] = True
                        if ch == '.':
                            for j in xrange(i+1, lens+1): match_[j] = True
                            i = lens
                        else:
                            j = i
                            while j < lens and s[j] == ch: 
                                match_[j + 1] = True
                                j += 1
                            i = j
                    i += 1
            match = match_
        return match[lens]

if __name__ == '__main__':
    print Solution().isMatch('ab', 'abc*')




