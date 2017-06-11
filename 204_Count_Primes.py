'''
Count the number of prime numbers less than a non-negative number, n.
'''

class Solution(object):
    def countPrimes(self, n):
        primes = []
        for i in xrange(2, n):
            isPrime = True
            for num in primes:
                if i % num == 0:
                    isPrime = False
                    break
                if num * num > i: break
            if isPrime: primes.append(i)
        return len(primes)

import unittest
class Test(unittest.TestCase):
    def test1(self):
        ans = [0, 0, 0, 1, 2, 2, 3, 3, 4, 4, 4]
        for n in xrange(10):
            self.assertEqual(Solution().countPrimes(n), ans[n])
    def test2(self):
        self.assertEqual(Solution().countPrimes(1000000), 78498)

if __name__ == '__main__':
    unittest.main()

