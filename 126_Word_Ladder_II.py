'''
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
'''


from Queue import Queue

class Solution(object):
    def __init__(self):
        self.alphabets = 'abcdefghijklmnopqrstuvwxyz'
    def findLadders(self, beginWord, endWord, wordList):
        l = len(wordList)
        lword = len(beginWord)
        wordList = set(wordList)
        step = {w:l+2 for w in wordList}
        if beginWord in wordList: step[beginWord] = 1
        if endWord not in wordList: return []
        q = Queue()
        minl = len(wordList)
        for i in xrange(lword):
            for ch in self.alphabets:
                word = beginWord[:i] + ch + beginWord[i+1:]
                if word in wordList:
                    step[word] = 2
                    if word == endWord: minl = 2
                    q.put(word)
        while q.qsize() > 0:
            word = q.get()
            if step[word] >= minl: break
            for i in xrange(lword):
                for ch in self.alphabets:
                    w = word[:i] + ch + word[i+1:]
                    if w in wordList and step[w] > step[word] + 1:
                        step[w] = step[word] + 1
                        if w == endWord: minl = step[word] + 1
                        q.put(w)
        def find_paths(step, word, path):
            if step[word] == 2: return [path]
            res = []
            for i in xrange(len(word)):
                for ch in self.alphabets:
                    new_word = word[:i] + ch + word[i+1:]
                    if new_word in step and step[new_word] == step[word] - 1: res += find_paths(step, new_word, path[:] + [new_word])
            return res
        return [[beginWord] + list(reversed(path)) + [endWord] for path in find_paths(step, endWord, [])]

if __name__ == '__main__':
    print(Solution().findLadders('hit', 'cog', ["hot","dot","dog","lot","log","cog"]))
    print(Solution().findLadders('ab', 'cd', ['ab', 'bd', 'cd']))
    print(Solution().findLadders('ab', 'cd', ['ad', 'bd', 'cb', 'cd']))
    print(Solution().findLadders('a', 'b', []))
