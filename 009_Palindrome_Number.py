'''
Determine whether an integer is a palindrome. Do this without extra space.
'''


class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """

        if x < 0: return False
        elif x < 10: return True

        import math
        power10 = 10 ** int(math.log10(x))

        while power10 > 1:
            if x % 10 != x // power10: return False
            x = x % power10 // 10
            power10 /= 100

        return True

if __name__ == '__main__':
    solution = Solution()
    print(solution.isPalindrome(1))
