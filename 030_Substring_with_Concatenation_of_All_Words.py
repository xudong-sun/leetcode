'''
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
'''

class Solution(object):
    def findSubstring(self, s, words):
        if len(s) == 0 or len(words) == 0: return []
        res = []
        word_total = {}
        for word in words:
            if word in word_total: word_total[word] += 1
            else: word_total[word] = 1
        lw = len(words[0])
        tlw = lw * len(words)
        ls = len(s)
        word_count = {}
        for i in xrange(lw):
            left = right = i
            for word in word_total: word_count[word] = 0
            while right <= ls - lw:
                w = s[right:right+lw]
                if w in word_count:
                    if word_count[w] < word_total[w]:
                        word_count[w] += 1
                        right += lw
                        if right - left == tlw:
                            res.append(left)
                            ww = s[left:left+lw]
                            word_count[ww] -= 1
                            left += lw
                    else:
                        while True:
                            ww = s[left:left+lw]
                            word_count[ww] -= 1
                            left += lw
                            if ww == w: break
                        if left > ls - tlw: break
                else:
                    right += lw
                    if right > ls - tlw: break
                    for word in word_total: word_count[word] = 0
                    left = right
        return res

if __name__ == '__main__':
    print Solution().findSubstring('abcabcaabc', ['abc', 'bca', 'bca'])


