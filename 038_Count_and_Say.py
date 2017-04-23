'''
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
'''

class Solution(object):
    def countAndSay(self, n):
        def get_next(string):
            ch, cnt = string[0], 1
            res = ''
            for s in string[1:]:
                if s == ch: cnt += 1
                else:
                    res += str(cnt) + ch
                    ch, cnt = s, 1
            return res + str(cnt) + ch
        if n == 1: return '1'
        s = '11'
        for _ in xrange(2, n): s = get_next(s)
        return s

if __name__ == '__main__':
    print Solution().countAndSay(5)

