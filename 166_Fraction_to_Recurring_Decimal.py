'''
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
'''


class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        if numerator == 0: return '0'
        sign = 1
        if numerator < 0: sign, numerator = -sign, -numerator
        if denominator < 0: sign, denominator = -sign, -denominator
        sign = '' if sign == 1 else '-'
        div, r = numerator / denominator, numerator % denominator
        if r == 0: return sign + str(div)
        frac_list = []
        frac_map = {}
        frac_map[r] = p = 0
        while r != 0:
            r *= 10
            d, r = r / denominator, r % denominator
            frac_list.append(str(d))
            p += 1
            if r in frac_map: break
            else: frac_map[r] = p
        if r == 0: return sign + str(div) + '.' + ''.join(frac_list)
        else:
            start = frac_map[r]
            return sign + str(div) + '.' + ''.join(frac_list[:start]) + '(' + ''.join(frac_list[start:]) + ')'

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().fractionToDecimal(1, 2), '0.5')
    def test2(self):
        self.assertEqual(Solution().fractionToDecimal(4, 2), '2')
    def test3(self):
        self.assertEqual(Solution().fractionToDecimal(2, 3), '0.(6)')
    def test4(self):
        self.assertEqual(Solution().fractionToDecimal(8, 7), '1.(142857)')
        self.assertEqual(Solution().fractionToDecimal(1, 13), '0.(076923)')
    def test5(self):
        self.assertEqual(Solution().fractionToDecimal(2, 30), '0.0(6)')
    def test6(self):
        self.assertEqual(Solution().fractionToDecimal(0, 1), '0')
        self.assertEqual(Solution().fractionToDecimal(0, -1), '0')
    def test7(self):
        self.assertEqual(Solution().fractionToDecimal(-1, 8), '-0.125')
        self.assertEqual(Solution().fractionToDecimal(1, -8), '-0.125')
        self.assertEqual(Solution().fractionToDecimal(-1, -8), '0.125')

if __name__ == '__main__':
    unittest.main()

