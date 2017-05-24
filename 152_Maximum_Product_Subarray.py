'''
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
'''


class Solution(object):
    def maxProduct(self, nums):
        l = len(nums)
        if l == 0: return 0
        max_product = max_abs = max_pos = nums[0]
        for num in nums[1:]:
            if abs(max_abs * num) > abs(num): max_abs = max_abs * num
            else: max_abs = num
            max_pos = max(max_abs * num, max_pos * num, num)
            max_product = max(max_product, max_pos)
        return max_product

if __name__ == '__main__':
    print Solution().maxProduct([2,3,-2,4])

