'''
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
'''


class Solution(object):
    def fullJustify(self, words, maxWidth):
        def add_spaces(words, L, s):
            ns = L - s
            if len(words) == 1: return words[0] + ' '*ns
            z = len(words) - 1
            q, k = ns // z, ns % z
            return (' '*(q+1)).join(words[:k+1]) + ' '*q + (' '*q).join(words[k+1:])
        lw = len(words)
        l = [len(w) for w in words]
        res = []
        j = -1
        while True:
            ll, i = 0, j
            while j < lw-1 and ll + l[j+1] <= maxWidth:
                j += 1
                ll += l[j] + 1
            if j == lw-1:
                res.append(' '.join(words[i+1:j+1]) + ' '*(maxWidth - ll + 1))
                break
            else: res.append(add_spaces(words[i+1:j+1], maxWidth, ll-j+i))
        return res

if __name__ == '__main__':
    print(Solution().fullJustify(['ab', 'ab', 'abc'], 5))


