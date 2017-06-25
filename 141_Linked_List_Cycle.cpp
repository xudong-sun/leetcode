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

#include "essentials.h"

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL) return false;
		ListNode *slow = head, *fast = head;
		while (1) {
			fast = fast->next; if (fast == NULL) break;
			fast = fast->next; if (fast == NULL) break;
			slow = slow->next;
			if (slow == fast) return true;
		}
		return false;
	}
};

int main() {
	Solution* sol = new Solution();
	auto list = new ListNode(std::vector < int > {1, 2, 3, 4, 5});
	std::cout << sol->hasCycle(list) << std::endl;
	delete sol;
	commons::pause();
}