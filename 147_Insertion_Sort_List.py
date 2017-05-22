'''
Sort a linked list using insertion sort.
'''


from structs.singly_linked_list import ListNode, generate_list

class Solution(object):
    def insertionSortList(self, head):
        if head is None: return head
        node = head.next
        head.next = None
        while node is not None:
            if node.val < head.val:
                tmp = node
                node = node.next
                tmp.next = head
                head = tmp
            else:
                p = head
                while p.next and p.next.val < node.val: p = p.next
                tmp = node
                node = node.next
                tmp.next = p.next
                p.next = tmp
        return head

if __name__ == '__main__':
    l = generate_list([3,2,1])
    print Solution().insertionSortList(l)
    l = generate_list([1,2,3])
    print Solution().insertionSortList(l)
    l = generate_list([4,3,1,2])
    print Solution().insertionSortList(l)
    l = generate_list([1])
    print Solution().insertionSortList(l)
    l = None
    print Solution().insertionSortList(l)
    l = generate_list([2,6,4,9,1,3,7,2,3])
    print Solution().insertionSortList(l)
    l = generate_list(range(5000))
    l = Solution().insertionSortList(l)


