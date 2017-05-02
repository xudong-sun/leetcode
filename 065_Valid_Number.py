'''
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
'''

import re

class Solution(object):
    def isNumber(self, s):
        pattern = r'^\s*[+-]?((\d+(\.\d*)?)|(\.\d+))([eE][+-]?\d+)?\s*$'
        number = re.compile(pattern)
        return bool(number.match(s))

if __name__ == '__main__':
    print(Solution().isNumber('-.1e-1'))

