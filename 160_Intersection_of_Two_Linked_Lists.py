'''
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 - a2
                   \
                     c1 - c2 - c3
                   /            
B:     b1 - b2 - b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
'''


from structs.singly_linked_list import generate_list, ListNode
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        if not headA or not headB: return None
        # connect tail with headB
        tail = headA
        while tail.next: tail = tail.next
        tail.next = headB
        try:
            # the rest is the same as 142_Linked_List_Cycle_II
            slow, fast = headA, headA.next
            while slow != fast:
                slow = slow.next
                try: fast = fast.next.next
                except: return None
            slow, fast = headA, fast.next
            while slow != fast:
                slow = slow.next
                fast = fast.next
            return slow
        finally: tail.next = None

if __name__ == '__main__':
    l1 = generate_list([1,2,6,7,8])
    l2 = generate_list([3,4,5])
    l2.next.next.next = l1.next.next
    print l1
    print l2
    print Solution().getIntersectionNode(l1, l2)
    print '-'*20
    l1 = generate_list([3,4,5])
    l2 = generate_list([1,2])
    l2.next.next = l1
    print l1
    print l2
    print Solution().getIntersectionNode(l1, l2)
    print Solution().getIntersectionNode(l2, l1)
    print '-'*20
    l1 = generate_list([1,2,3])
    l2 = generate_list([4,5,6])
    print Solution().getIntersectionNode(l1, l2)
    print '-'*20
    l1 = generate_list([])
    l2 = generate_list([1,2,3])
    print Solution().getIntersectionNode(l1, l2)

