'''
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

return 0 if overflow
'''


class Solution(object):
    def digits(self, x):
        while (x > 0):
            yield x % 10
            x //= 10

    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """

        ans = 0
        for digit in self.digits(abs(x)):
            ans = ans * 10 + digit

        if ans > 2 ** 31: return 0
        else: return ans if x >= 0 else -ans

if __name__ == '__main__':
    print(Solution().reverse(10000000003))
