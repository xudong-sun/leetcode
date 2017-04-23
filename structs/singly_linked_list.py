# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
    def __str__(self):
        return str(self.val) if self.next is None else str(self.val) + ' -> ' + str(self.next)

def generate_list(s):
    '''generate a singly-linked list
    s: a list of values
    e.g. generate_list([1, 2, 3]) gives 1 -> 2 -> 3 -> None
    '''
    if len(s) == 0: return None
    l = p = ListNode(s[0])
    for c in s[1:]:
        n = ListNode(c)
        p.next = n
        p = n
    p.next = None
    return l

