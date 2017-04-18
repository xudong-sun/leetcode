/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

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
Fist, check 141_Linked_list_Cycle for detecting whether there's a cycle
Next, use math. Suppose distance before the cycle is a; Distance within the cycle, before the first time fast and slow meets, is b, and the distance within the cycle after that is c.
and you'll find a = c + n (b+c)
So, let slow start from head, and fast start from the node they first meet, and they both move one step a time. The next time they meet is the answer.
*/

#include <cstdlib>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) 
	{
		if (head == NULL) return NULL;
		ListNode *slow = head, *fast = head;
		while (1)
		{
			fast = fast->next; if (fast == NULL) break;
			fast = fast->next; if (fast == NULL) break;
			slow = slow->next;
			if (slow == fast)
			{
				slow = head;
				while (1)
				{
					if (slow == fast) return fast;
					slow = slow->next; fast = fast->next;
				}
			}
		}
		return NULL;
	}
};