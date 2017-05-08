'''
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
'''


class Solution(object):
    def removeDuplicates(self, nums):
        l = len(nums)
        if l <= 2: return l
        i = j = 0
        x, z = nums[0], 1
        while j < l - 1:
            j += 1
            if nums[j] == x:
                z += 1
                if z <= 2: i += 1
            else:
                x, z = nums[j], 1
                i += 1
            nums[i] = nums[j]
        return i + 1

if __name__ == '__main__':
    l = []
    print Solution().removeDuplicates(l)
    print l
            
            

