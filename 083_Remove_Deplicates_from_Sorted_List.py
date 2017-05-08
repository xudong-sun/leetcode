'''
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
'''


from structs.singly_linked_list import generate_list

class Solution(object):
    def deleteDuplicates(self, head):
        if head == None: return head
        cur = head
        while cur.next != None:
            if cur.val == cur.next.val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return head

if __name__ == '__main__':
    l = generate_list([])
    print Solution().deleteDuplicates(l)

