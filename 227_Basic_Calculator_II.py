'''
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

Note: Do not use the eval built-in library function.
'''


class Solution(object):
    def calculate(self, s):
        a = []
        x, z, sign, is_mul = 1, 0, 1, True
        for ch in s:
            if ch == '+':
                if is_mul: a.append(x * z * sign)
                else: a.append(x / z * sign)
                x, z, sign, is_mul = 1, 0, 1, True
            elif ch == '-':
                if is_mul: a.append(x * z * sign)
                else: a.append(x / z * sign)
                x, z, sign, is_mul = 1, 0, -1, True
            elif ch == '*':
                if is_mul: x, z = x*z, 0
                else: x, z = x/z, 0
                is_mul = True
            elif ch == '/':
                if is_mul: x, z = x*z, 0
                else: x, z = x/z, 0
                is_mul = False
            elif ch.isdigit():
                z = 10 * z + ord(ch)-48
        if is_mul: a.append(x * z * sign)
        else: a.append(x / z * sign)
        return sum(a)

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().calculate('3+2*2'), 7)
    def test2(self):
        self.assertEqual(Solution().calculate(' 3/2 '), 1)
    def test3(self):
        self.assertEqual(Solution().calculate('3+5 / 2'), 5)
    def test4(self):
        self.assertEqual(Solution().calculate('30*12 - 108/4+27'), 360)
    def test5(self):
        self.assertEqual(Solution().calculate('1+5*4*3/2*1-27'), 4)
    def test6(self):
        self.assertEqual(Solution().calculate('14 - 3/2'), 13)
    def test7(self):
        self.assertEqual(Solution().calculate(''), 0)

if __name__ == '__main__':
    unittest.main()

