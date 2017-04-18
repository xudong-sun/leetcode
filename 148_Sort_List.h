/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

/*
Solution: Merge Sort
*/

#include <cstdlib>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) 
	{
		if (head == NULL) return NULL;
		ListNode* half = halfPrevious(head);
		ListNode* mid = half->next;
		if (mid == NULL) return head;
		half->next = NULL;
		return mergeList(sortList(head), sortList(mid));
	}
private:
	ListNode* mergeList(ListNode* head1, ListNode* head2)
	{
		ListNode* head;
		if (head1 == NULL) return head2;
		if (head2 == NULL) return head1;
		if (head1->val <= head2->val)
		{
			head = head1; head1 = head1->next;
		}
		else
		{
			head = head2; head2 = head2->next;
		}
		ListNode* current = head;
		while (head1 != NULL && head2 != NULL)
		{
			if (head1->val <= head2->val)
			{
				current->next = head1; head1 = head1->next;
			}
			else
			{
				current->next = head2; head2 = head2->next;
			}
			current = current->next;
		}
		if (head1 == NULL) current->next = head2; else current->next = head1;
		return head;
	}
	ListNode* halfPrevious(ListNode* head)
	{
		ListNode* fast = head;
		while (1)
		{
			fast = fast->next; if (fast == NULL) break;
			fast = fast->next; if (fast == NULL) break;
			head = head->next;
		}
		return head;
	}
};