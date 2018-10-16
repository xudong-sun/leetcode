"""
Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input:
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].
"""

from collections import defaultdict

# map_char_to_word: char -> list[int], which words are waiting for that character to appear in S

class Solution(object):
    def numMatchingSubseq(self, S, words):
        ans = 0
        ptr = [0] * len(words)
        map_char_to_word = defaultdict(list)
        for i, word in enumerate(words): map_char_to_word[word[0]].append(i)
        for ch in S:
            indices = map_char_to_word[ch]
            map_char_to_word[ch] = []
            for j in indices:
                ptr[j] += 1
                if ptr[j] == len(words[j]): ans += 1
                else: map_char_to_word[words[j][ptr[j]]].append(j)
        return ans

import unittest
class Test(unittest.TestCase):
    def test1(self):
        S = 'abcde'
        words = ['a', 'bb', 'acd', 'ace']
        self.assertEqual(Solution().numMatchingSubseq(S, words), 3)
    def test2(self):
        S = 'aaca'
        words = ['a', 'b', 'aa', 'aaa', 'aaaa', 'caaa', 'ac', 'acc']
        self.assertEqual(Solution().numMatchingSubseq(S, words), 4)

if __name__ == "__main__":
    unittest.main()



