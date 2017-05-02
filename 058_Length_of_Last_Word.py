'''
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
'''

class Solution(object):
    def lengthOfLastWord(self, s):
        s = s.rstrip(' ')
        return len(s) - s.rfind(' ') - 1

if __name__ == '__main__':
    print(Solution().lengthOfLastWord('tt ttt   '))

