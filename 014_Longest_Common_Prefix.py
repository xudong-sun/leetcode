'''
Write a function to find the longest common prefix string amongst an array of strings.
'''

class Solution(object):
    def longestCommonPrefix(self, strs):
        if len(strs) == 0: return ''
        if len(strs) == 1: return strs[0]
        l = min([len(s) for s in strs])
        i = 0
        while i < l:
            ss = strs[0][i]
            if not all([s[i] == ss for s in strs]): break
            i += 1
        return strs[0][:i]

if __name__ == '__main__':
    print Solution().longestCommonPrefix(['abc'])

