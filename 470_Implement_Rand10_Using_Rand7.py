'''
Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.

Do NOT use system's Math.random()
'''

import random
from collections import Counter

def rand7():
    return random.randint(1, 7)

# 1. get a uniform distribution [1,49] by calling rand7() twice
# 2. rejection sampling: if value lies in [1,40], return value%10; otherwise, reject and repeat
# Note: calling rand7() twice and add them up does NOT give a uniform distribution [1,14]
class Solution(object):
    def rand10(self):
        while True:
            value = rand7() * 7 + rand7()
            if 10 <= value < 50:
                return value % 10 + 1


if __name__ == "__main__":
    sol = Solution()
    print Counter([sol.rand10() for _ in xrange(10000)])

