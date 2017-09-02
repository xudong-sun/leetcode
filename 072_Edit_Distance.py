'''
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
'''


# basic DP equation:
# let a[i][j] = minimum # steps for word1[:i+1] to be converted to word2[:j+1]
# if word1[i] == word2[j]: a[i][j] = min(a[i][j-1] + 1, a[i-1][j] + 1, a[i-1][j-1])
# else: a[i][j] = min(a[i][j-1] + 1, a[i-1][j] + 1, a[i-1][j-1] + 1)
# The above equation can be implemented with O(mn), space O(n)
class Solution(object):
    def minDistance(self, word1, word2):
        l1, l2 = len(word1), len(word2)
        a = [i for i in range(l1+1)]
        aa = a[:]
        for j in range(l2):
            aa[0] = j+1
            for i in range(1, l1+1):
                if word1[i-1] != word2[j]:
                    aa[i] = min(a[i]+1, aa[i-1]+1, a[i-1]+1)
                else:
                    aa[i] = min(a[i]+1, aa[i-1]+1, a[i-1])
            a = aa[:]
        return a[l1]

if __name__ == '__main__':
    print(Solution().minDistance('accdefg', 'abcdegh'))

