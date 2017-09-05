'''
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

    0.1 < 1.1 < 1.2 < 13.37
'''

class Solution(object):
    def compareVersion(self, version1, version2):
        values1 = [int(s) for s in version1.split('.')]
        values2 = [int(s) for s in version2.split('.')]
        l1, l2 = len(values1), len(values2)
        l = max(l1, l2)
        if l1 < l: values1 += [0] * (l - l1)
        if l2 < l: values2 += [0] * (l - l2)
        return cmp(values1, values2)

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().compareVersion('1.3', '1.2'), 1)
        self.assertEqual(Solution().compareVersion('1.2', '1.3'), -1)
        self.assertEqual(Solution().compareVersion('1.2', '1.2'), 0)
    def test2(self):
        self.assertEqual(Solution().compareVersion('13.1', '9.8.2'), 1)
    def test3(self):
        self.assertEqual(Solution().compareVersion('1.2', '1.2.1'), -1)
        self.assertEqual(Solution().compareVersion('1.2', '1.2.0'), 0)
    def test4(self):
        self.assertEqual(Solution().compareVersion('1.1.1.1', '1.1.1'), 1)
    def test5(self):
        self.assertEqual(Solution().compareVersion('1.1', '1.1.0.1'), -1)
    def test6(self):
        self.assertEqual(Solution().compareVersion('0.1', '1'), -1)

if __name__ == "__main__":
    unittest.main()
