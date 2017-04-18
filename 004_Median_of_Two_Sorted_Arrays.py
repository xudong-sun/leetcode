'''
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
'''

class Solution(object):
    def _find_nth(self, nums1, nums2, x1, y1, x2, y2, n, even):
        '''find the nth largest number in the two subsets nums1[x1:y1], num2[x2:y2]
        if even == True: return the average of nth and (n+1)th
        '''
        if x1 == y1:
            if even: return float(nums2[x2 + n - 1] + nums2[x2 + n]) / 2
            else: return nums2[x2 + n - 1]
        elif x2 == y2:
            if even: return float(nums1[x1 + n - 1] + nums1[x1 + n]) / 2
            else: return nums1[x1 + n - 1]
        if n == 1:
            if even:
                l1, l2 = y1 - x1, y2 - x2
                if l1 == l2 == 1: return float(nums1[x1] + nums2[x2]) / 2
                elif l1 == 1: return float(min(nums1[x1] + nums2[x2], nums2[x2] + nums2[x2 + 1])) / 2
                elif l2 == 1: return float(min(nums1[x1] + nums2[x2], nums1[x1] + nums1[x1 + 1])) / 2
                else: return float(min(nums1[x1] + nums2[x2], nums1[x1] + nums1[x1 + 1], nums2[x2] + nums2[x2 + 1])) / 2
            else: return min(nums1[x1], nums2[x2])
        # distribute n
        l1, l2 = y1 - x1, y2 - x2
        n1, n2 = min(l1, n / 2), min(l2, n / 2)
        # find the n1-th number in nums1[x1:y1], n2-th number in nums2[x2:y2]
        v1, v2 = nums1[x1 + n1 - 1], nums2[x2 + n2 - 1]
        # discard either the first n1 numbers in nums1 or the first n2 numbers in nums2
        if v1 < v2: return self._find_nth(nums1, nums2, x1 + n1, y1, x2, y2, n - n1, even)
        else: return self._find_nth(nums1, nums2, x1, y1, x2 + n2, y2, n - n2, even)

    def findMedianSortedArrays(self, nums1, nums2):
        l1, l2 = len(nums1), len(nums2)
        return self._find_nth(nums1, nums2, 0, l1, 0, l2, (l1 + l2 + 1) / 2, (l1 + l2) % 2 == 0)

if __name__ == '__main__':
    print Solution().findMedianSortedArrays([], [1, 2])


