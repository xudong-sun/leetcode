'''
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
'''

class Solution(object):
    def multiply(self, num1, num2):
        x1 = [int(c) for c in num1[::-1]]
        x2 = [int(c) for c in num2[::-1]]
        l1, l2 = len(x1), len(x2)
        y = [0] * (l1 + l2)
        for i, d1 in enumerate(x1):
            for j, d2 in enumerate(x2):
                d = d1 * d2
                y[i+j] += d % 10
                y[i+j+1] += d / 10
        for i in xrange(l1+l2-1):
            y[i+1] += y[i] / 10
            y[i] %= 10
        h = l1 + l2 - 1
        while h > 0 and y[h] == 0: h -= 1
        return ''.join(str(v) for v in reversed(y[:h+1]))

if __name__ == '__main__':
    print Solution().multiply('10', '512')

