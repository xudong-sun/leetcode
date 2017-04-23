'''
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
'''

class Solution(object):
    def __init__(self):
        self.map_num_to_string = {'1': '*', '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz', '0': ' '}
    def _get_string(self, level, string):
        if level == self.len_digits:
            self.result.append(string)
            return
        for ch in self.map_num_to_string[self.digits[level]]:
            self._get_string(level + 1, string + ch)
    def letterCombinations(self, digits):
        if len(digits) == 0: return []
        self.digits = digits
        self.len_digits = len(digits)
        self.result = []
        self._get_string(0, '')
        return self.result

if __name__ == '__main__':
    print Solution().letterCombinations('23109')


