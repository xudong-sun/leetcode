'''
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
'''


class Solution(object):
    def getPermutation(self, n, k):
        t = [1] * (n-1)
        for i in range(1, n-1): t[i] = t[i-1] * (i+1)
        b = [True] * n
        s = []
        def mth_true(m):
            i = j = -1
            while j < m:
                i += 1
                if b[i]: j += 1
            return i+1
        k -= 1
        for i in range(n-2, -1, -1):
            m, k = k // t[i], k % t[i]
            j = mth_true(m)
            s.append(j)
            b[j-1] = False
        s.append(mth_true(0))
        return ''.join([str(v) for v in s])

if __name__ == '__main__':
    print(Solution().getPermutation(9,100))

