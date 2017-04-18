/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

/*
Solution:
two pointers: slow, fast.
slow moves one step a time; fast moves two step a time
if fast and slow meets, it has a cycle, otherwise it does not.
*/

#include <cstdlib>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) 
	{
		if (head == NULL) return false;
		ListNode *slow = head, *fast = head;
		while (1)
		{
			fast = fast->next; if (fast == NULL) break;
			fast = fast->next; if (fast == NULL) break;
			slow = slow->next;
			if (slow == fast) return true;
		}
		return false;
	}
};