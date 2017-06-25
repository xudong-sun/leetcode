#ifndef __ESSENTIALS_H
#define __ESSENTIALS_H

#include <string>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <regex>
#include <algorithm>

#include <assert.h>

#include "commons.h"
#include "print_utils.h"

class ListNode {
public:
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(std::vector<int>& nums) : val(nums[0]) {
		auto node = this;
		for (size_t i = 1; i < nums.size(); i++) {
			int num = nums[i];
			auto new_node = new ListNode(num);
			node->next = new_node;
			node = new_node;
		}
	}
	int val;
	ListNode *next;
};

std::ostream& operator<<(std::ostream& os, ListNode list) {
	os << list.val;
	if (list.next != NULL) {
		os << " -> " << *(list.next);
	}
	return os;
}

#endif