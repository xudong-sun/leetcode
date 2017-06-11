'''
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
'''


from collections import defaultdict

class TrieNode(object):
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.is_word = False

class Trie(object):
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for ch in word: node = node.children[ch]
        node.is_word = True

    def search(self, word):
        node = self._get_node(word)
        return bool(node) and node.is_word

    def startsWith(self, prefix):
        return bool(self._get_node(prefix))

    def _get_node(self, s):
        node = self.root
        for ch in s:
            node = node.children.get(ch)
            if node is None: return None
        return node

import unittest
class Test(unittest.TestCase):
    def test1(self):
        t = Trie()
        self.assertFalse(t.search('a'))
        self.assertFalse(t.startsWith('a'))
        t.insert('abc')
        t.insert('abd')
        self.assertTrue(t.search('abc'))
        self.assertFalse(t.search('ab'))
        self.assertTrue(t.search('abd'))
        self.assertFalse(t.search('abe'))
        self.assertFalse(t.startsWith('abe'))
        self.assertTrue(t.startsWith('ab'))
        self.assertFalse(t.search(''))
        self.assertTrue(t.startsWith(''))
    def test2(self):
        t = Trie()
        self.assertFalse(t.search('a'))

if __name__ == '__main__':
    unittest.main()

