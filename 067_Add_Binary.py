'''
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
'''


class Solution(object):
    def addBinary(self, a, b):
        if len(b) > len(a): a, b = b, a
        l1, l2 = len(a), len(b)
        a = [int(x) for x in a[::-1]]
        b = [int(x) for x in b[::-1]]
        r = [a[i] + b[i] for i in range(l2)] + a[l2:]
        for i in range(l1-1):
            if r[i] > 1:
                r[i] -= 2
                r[i+1] += 1
        if r[-1] > 1:
            r[-1] -= 2
            r.append(1)
        return ''.join([str(d) for d in r[::-1]])

if __name__ == '__main__':
    print(Solution().addBinary('1', '11111'))

