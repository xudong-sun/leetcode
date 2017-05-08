'''
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
'''


from structs.singly_linked_list import generate_list, ListNode

class Solution(object):
    def deleteDuplicates(self, head):
        if head == None: return head
        dummy = ListNode(0)
        dummy.next = head
        pre, cur = dummy, head
        delete_cur = False
        while cur.next != None:
            if cur.val == cur.next.val:
                delete_cur = True
                cur.next = cur.next.next
            elif delete_cur:
                cur = cur.next
                pre.next = cur
                delete_cur = False
            else:
                cur = cur.next
                pre = pre.next
        if delete_cur: pre.next = None
        return dummy.next

if __name__ == '__main__':
    l = generate_list([])
    print Solution().deleteDuplicates(l)

