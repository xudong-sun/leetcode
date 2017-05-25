'''
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
'''


# O(n) time, O(1) space
# divide into v-groups
# e.g. 1, 2, 3, 2, 4, 3, 2, 2, 3, 2, 1
#  ->  (1,2),(3,2),(4,3,2,2),(3,2,1)
# for this code:
# x: length of the v-group
# subtotal: total #candies in this v-group (relative)
# m: min #candies in this v-group (relative)
# h: #candies for current child (relative)
# for adjustment, each child should be given (m-1) fewer candies
#
# follow-up: can be improved by dividing into "\"-groups
#  ->  1,2,(3,2),(4,3,2),2,(3,2,1)

class Solution(object):
    def candy(self, ratings):
        total = 0
        l = len(ratings)
        if l == 1: return 1
        elif l == 0: return 0
        i = 0
        x = subtotal = m = h = 1
        def add_adjusted_total(total, x, subtotal, m):
            if m > 1: return total + subtotal + (1-m) * (x-1), 1 - m
            else: return total + subtotal + (1-m) * x, 1 - m
        while i < l - 2:
            i += 1
            if ratings[i] < ratings[i-1]:
                h -= 1
                m = min(m,h)
                subtotal += h
                x += 1
            elif ratings[i] == ratings[i-1]:
                total, _ = add_adjusted_total(total, x, subtotal, m)
                x = subtotal = h = m = 1
            else:
                if ratings[i+1] < ratings[i]:
                    total, dh = add_adjusted_total(total, x, subtotal, m)
                    h += dh + 1
                    m = h
                    subtotal = h
                    x = 1
                else:
                    h += 1
                    subtotal += h
                    x += 1
        if ratings[-1] == ratings[-2]:
            total, _ = add_adjusted_total(total, x, subtotal, m)
            total += 1
        else:
            if ratings[-1] > ratings[-2]: h += 1
            elif ratings[-1] < ratings[-2]:
                h -= 1
                m = min(m,h)
            total, _ = add_adjusted_total(total, x + 1, subtotal + h, m)
        return total

if __name__ == '__main__':
    print Solution().candy([1,2,3,2,4,3,2,2,3,2,1])
    print Solution().candy([1,2,3,3])
    print Solution().candy([2,2,1,2])
    print Solution().candy([1,2,3,3,3,2])
    print Solution().candy([1,2,3,3,2])
    print Solution().candy([2,3])
    print Solution().candy([1])
    print Solution().candy([])

