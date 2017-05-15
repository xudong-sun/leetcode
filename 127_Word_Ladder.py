'''
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
'''


# BFS
# can be improved with two-end BFS
from queue import Queue

class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        l = len(wordList)
        lword = len(beginWord)
        wordList = set(wordList)
        step = {w:l+2 for w in wordList}
        alphabets = 'abcdefghijklmnopqrstuvwxyz'
        q = Queue()
        for i in range(lword):
            for ch in alphabets:
                word = beginWord[:i] + ch + beginWord[i+1:]
                if word in wordList:
                    if word == endWord: return 2
                    q.put(word)
                    step[word] = 2
        while q.qsize() > 0:
            word = q.get()
            for i in range(lword):
                for ch in alphabets:
                    w = word[:i] + ch + word[i+1:]
                    if w in wordList and step[w] > step[word] + 1:
                        if w == endWord: return step[word] + 1
                        q.put(w)
                        step[w] = step[word] + 1
        return 0


if __name__ == '__main__':
    print(Solution().ladderLength('hit', 'cog', ["hot","dot","dog","lot","log","cog"]))
    print(Solution().ladderLength('ab', 'cd', ['ab', 'bd', 'cd']))
    print(Solution().ladderLength('a', 'b', []))



