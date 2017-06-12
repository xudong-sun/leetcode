'''
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.
'''


# Trie
from collections import defaultdict
class TrieNode(object):
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.word = None
class Solution(object):
    def findWords(self, board, words):
        # build trie
        trie = TrieNode()
        for word in words:
            node = trie
            for ch in word: node = node.children[ch]
            node.word = word
        # dfs
        res = []
        m = len(board)
        if m == 0: return []
        n = len(board[0])
        if n == 0: return []
        def walk(x, y, node):
            if node.word:
                res.append(node.word)
                node.word = None # one-time trie, avoid duplicates
            c, board[x][y] = board[x][y], '#' # use this trick to replace "visited"
            if x > 0:
                ch = board[x-1][y]
                next_node = node.children.get(ch)
                if next_node: walk(x-1, y, next_node)
            if x < m-1:
                ch = board[x+1][y]
                next_node = node.children.get(ch)
                if next_node: walk(x+1, y, next_node)
            if y > 0:
                ch = board[x][y-1]
                next_node = node.children.get(ch)
                if next_node: walk(x, y-1, next_node)
            if y < n-1:
                ch = board[x][y+1]
                next_node = node.children.get(ch)
                if next_node: walk(x, y+1, next_node)
            board[x][y] = c
        for i in xrange(m):
            for j in xrange(n):
                node = trie.children.get(board[i][j])
                if node: walk(i, j, node)
        return res

import unittest
class Test(unittest.TestCase):
    def test1(self):
        board = [['o','a','a','n'],['e','t','a','e'],['i','h','k','r'],['i','f','l','v']]
        words = ['oath','pea','eat','rain']
        self.assertItemsEqual(Solution().findWords(board, words), ['eat', 'oath'])

if __name__ == '__main__':
    unittest.main()

