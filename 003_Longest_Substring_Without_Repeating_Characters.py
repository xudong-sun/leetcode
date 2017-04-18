'''
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
'''

# TODO could be improved

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        maxl = 0
        chars = set()
        i = j = 0
        lens = len(s)
        while j < lens:
            c = s[j]
            if c not in chars:
                chars.add(c)
                j += 1
            else:
                if j - i > maxl: maxl = j - i
                while True:
                    ch = s[i]
                    chars.remove(ch)
                    i += 1
                    if ch == c: break
        if j - i > maxl: maxl = j - i
        return maxl

if __name__ == '__main__':
    print Solution().lengthOfLongestSubstring('aabcdef')

