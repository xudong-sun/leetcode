'''
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
'''


from collections import defaultdict

class TrieNode(object):
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.is_word = False

    def _search(self, word, idx):
        ch = word[idx]
        if ch == '.':
            if idx == len(word) - 1:
                for c in self.children:
                    if self.children[c].is_word: return True
                return False
            else:
                for c in self.children:
                    if self.children[c]._search(word, idx+1): return True
                return False
        else:
            node = self.children.get(ch)
            if node is None: return False
            if idx == len(word) - 1: return node.is_word
            else: return node._search(word, idx+1)

class WordDictionary(object):
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word):
        node = self.root
        for ch in word: node = node.children[ch]
        node.is_word = True

    def search(self, word):
        return self.root._search(word, 0)

import unittest
class Test(unittest.TestCase):
    def test1(self):
        d = WordDictionary()
        d.addWord("bad")
        d.addWord("dad")
        d.addWord("mad")
        self.assertFalse(d.search("pad"))
        self.assertTrue(d.search("bad"))
        self.assertTrue(d.search(".ad"))
        self.assertTrue(d.search("b.."))
        self.assertFalse(d.search('..'))
        d.addWord('ax')
        self.assertFalse(d.search('.ax'))
        self.assertFalse(d.search('ax.'))
        self.assertTrue(d.search('..'))

if __name__ == '__main__':
    unittest.main()

