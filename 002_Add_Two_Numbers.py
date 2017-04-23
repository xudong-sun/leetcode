'''
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
'''

from structs.singly_linked_list import ListNode, generate_list

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        v = l1.val + l2.val
        if v > 9:
            v -= 10
            z = 1
        else: z = 0
        result = prev = ListNode(v)
        l1, l2 = l1.next, l2.next
        while True:
            if l1 is not None and l2 is not None:
                v = l1.val + l2.val + z
                if v > 9:
                    v -= 10
                    z = 1
                else: z = 0
                node = ListNode(v)
                prev.next = node
                prev = node
                l1, l2 = l1.next, l2.next
            elif l1 is None and l2 is not None:
                v = l2.val + z
                if v <= 9:
                    node = ListNode(v)
                    prev.next = node
                    node.next = l2.next
                    return result
                else:
                    v -= 10
                    z = 1
                    node = ListNode(v)
                    prev.next = node
                    prev = node
                    l2 = l2.next
            elif l1 is not None and l2 is None:
                v = l1.val + z
                if v <= 9:
                    node = ListNode(v)
                    prev.next = node
                    node.next = l1.next
                    return result
                else:
                    v -= 10
                    z = 1
                    node = ListNode(v)
                    prev.next = node
                    prev = node
                    l1 = l1.next
            else:
                if z == 0:
                    prev.next = None
                    return result
                else:
                    node = ListNode(z)
                    prev.next = node
                    node.next = None
                    return result

if __name__ == '__main__':
    l1 = generate_list([9, 9, 9, 9, 9])
    l2 = generate_list([1, 0, 0, 0, 0, 1])
    print Solution().addTwoNumbers(l1, l2)

