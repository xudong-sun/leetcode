'''
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
'''


class Solution(object):
    def wordBreak(self, s, wordDict):
        l = len(s)
        b = [True] + [False] * l
        wordDict = set(wordDict)
        wordLength = [len(word) for word in wordDict]
        wordLength = sorted(list(set(wordLength)))
        for i in xrange(l):
            for j in wordLength:
                if i-j < -1: break
                if b[i-j+1] and s[i-j+1:i+1] in wordDict:
                    b[i+1] = True
                    break
        return b[-1]

if __name__ == '__main__':
    print Solution().wordBreak('leetcode', ['leet', 'code'])
    print Solution().wordBreak('abcdef', ['a', 'b', 'c', 'd', 'cde', 'f'])

