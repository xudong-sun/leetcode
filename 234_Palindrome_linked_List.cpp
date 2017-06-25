/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

#include "essentials.h"

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL) return true;
		ListNode *slow = head, *fast = head, *pre = NULL;
		bool flag = false;
		do {
			fast = fast->next;
			if (fast == NULL) break;
			fast = fast->next;
			if (fast == NULL) {
				flag = true;
				break;
			}
			auto tmp = slow;
			slow = slow->next;
			tmp->next = pre;
			pre = tmp;
		} while (1);
		if (flag) {
			fast = slow->next;
			slow->next = pre;
		} else {
			fast = slow->next;
			slow = pre;
		}
		while (fast) {
			if (slow->val != fast->val) return false;
			slow = slow->next;
			fast = fast->next;
		}
		return true;
	}
};

int main() {
	auto sol = new Solution();
	auto list = new ListNode(std::vector < int > {1, 2, 3, 4, 5, 4, 3, 2, 1});
	assert(sol->isPalindrome(list));
	list = new ListNode(std::vector < int > {1, 2, 3, 4, 5, 5, 4, 3, 2, 1});
	assert(sol->isPalindrome(list));
	list = new ListNode(std::vector < int > {1, 2, 3, 4, 4, 3, 2, 1, 0});
	assert(!sol->isPalindrome(list));
	list = new ListNode(std::vector < int > {1, 2, 3, 4, 5, 3, 2, 1});
	assert(!sol->isPalindrome(list));
	list = new ListNode(std::vector < int > {1});
	assert(sol->isPalindrome(list));
	list = new ListNode(std::vector < int > {1, 1});
	assert(sol->isPalindrome(list));
	list = new ListNode(std::vector < int > {1, 2});
	assert(!sol->isPalindrome(list));
	assert(sol->isPalindrome(NULL));
	delete sol;
}