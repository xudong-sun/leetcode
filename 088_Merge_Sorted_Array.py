'''
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
'''


class Solution(object):
    def merge(self, nums1, m, nums2, n):
        nums3 = nums1[:m]
        i = j = 0
        while i < m and j < n:
            if nums3[i] < nums2[j]:
                nums1[i+j] = nums3[i]
                i += 1
            else: 
                nums1[i+j] = nums2[j]
                j += 1
        if i == m: nums1[i+j:m+n] = nums2[j:]
        elif j == n: nums1[i+j:m+n] = nums3[i:]

if __name__ == '__main__':
    nums1 = [1,3,6,7,8,0,0,0]
    nums2 = [9]
    Solution().merge(nums1, 5, nums2, 1)
    print nums1

