'''Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
'''


class Solution(object):
    def wordBreak(self, s, wordDict):
        l = len(s)
        b = [True] + [False] * l
        pos = [[] for _ in xrange(l+1)]
        wordDict = set(wordDict)
        wordLength = [len(word) for word in wordDict]
        wordLength = sorted(list(set(wordLength)))
        for i in xrange(l):
            for j in wordLength:
                if i-j < -1: break
                if b[i-j+1] and s[i-j+1:i+1] in wordDict:
                    b[i+1] = True
                    pos[i+1].append(j)
        def walk(p, res):
            if p == -1: return [' '.join(reversed(res))]
            ret = []
            for j in pos[p+1]:
                res.append(s[p-j+1:p+1])
                ret += walk(p-j, res)
                res.pop()
            return ret
        return walk(l-1, [])

if __name__ == '__main__':
    print Solution().wordBreak('leetcode', ['leet', 'code'])
    print Solution().wordBreak('abcdef', ['a', 'b', 'c', 'd', 'cde', 'cd', 'de', 'f'])
    print Solution().wordBreak('catsanddog', ['cat', 'cats', 'and', 'sand', 'dog'])

