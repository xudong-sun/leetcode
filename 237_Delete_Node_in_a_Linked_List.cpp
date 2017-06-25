/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
*/

#include "essentials.h"

class Solution {
public:
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
};

int main() {
	auto sol = new Solution();
	auto list = new ListNode(std::vector < int > {1, 2, 3, 4, 5});
	auto node = list->next->next;
	sol->deleteNode(node);
	std::cout << *list << std::endl;
	delete sol;
	commons::pause();
}