'''
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
'''


class Solution(object):
    def maxProduct(self, nums):
        max_product = max_neg = max_pos = nums[0]
        for num in nums[1:]:
            tmp1, tmp2 = max_neg * num, max_pos * num
            max_neg = min(tmp1, tmp2, num)
            max_pos = max(tmp1, tmp2, num)
            max_product = max(max_product, max_pos)
            #print max_neg, max_pos, max_product
        return max_product

if __name__ == '__main__':
    print Solution().maxProduct([2,3,-2,4])
    print Solution().maxProduct([2,8,-3,0,-6,3,-1,2,0,4,-9,2])
    print Solution().maxProduct([-10])
    print Solution().maxProduct([-1,-2,-9,-6])
    print Solution().maxProduct([-1,-2,9,-6])

