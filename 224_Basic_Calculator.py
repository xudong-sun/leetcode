'''
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
'''


class Solution(object):
    def calculate(self, s):
        ans = 0
        x = 0
        sign = 1
        sur_sign_stack = [1]
        for ch in s:
            if ch == '+':
                ans += sur_sign_stack[-1] * sign * x
                x, sign = 0, 1
            elif ch == '-':
                ans += sur_sign_stack[-1] * sign * x
                x, sign = 0, -1
            elif ch == '(':
                sur_sign_stack.append(sur_sign_stack[-1] * sign)
                x, sign = 0, 1
            elif ch == ')':
                ans += sur_sign_stack[-1] * sign * x
                sur_sign_stack.pop()
                x, sign = 0, 1
            elif ch in '0123456789':
                x = x * 10 + ord(ch)-48
        ans += sign * x
        return ans

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().calculate('1 + 1'), 2)
    def test2(self):
        self.assertEqual(Solution().calculate(' 2-1 + 2'), 3)
    def test3(self):
        self.assertEqual(Solution().calculate('(1+(4+5+2)-3)+(6+8)'), 23)
    def test4(self):
        self.assertEqual(Solution().calculate('-1+0-2'), -3)
    def test5(self):
        self.assertEqual(Solution().calculate('(1)'), 1)
    def test6(self):
        self.assertEqual(Solution().calculate('-(1+2)'), -3)
    def test7(self):
        self.assertEqual(Solution().calculate('10- ( 3+8 -(1+2 ) +4- 2)+ 8'), 8)
    def test8(self):
        self.assertEqual(Solution().calculate('100+99-98'), 101)
    def test9(self):
        self.assertEqual(Solution().calculate(''), 0)

if __name__ == '__main__':
    unittest.main()

