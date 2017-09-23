/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2
*/

#include "essentials.h"

#define __SOLUTION_2

#ifdef __SOLUTION_1
// use two heaps. O(logn), O(1), 142ms
// Heap 1 stores the smaller half; heap 2 stores the larger half
class MedianFinder {
public:
	MedianFinder() {}

	void addNum(int num) {
		if (large.size() == 0 || num <= -large.front()) {
			small.push_back(num);
			std::push_heap(small.begin(), small.end());
			if (small.size() > large.size() + 1) {
				std::pop_heap(small.begin(), small.end());
				large.push_back(-small.back());
				std::push_heap(large.begin(), large.end());
				small.pop_back();
			}
		}
		else {
			large.push_back(-num);
			std::push_heap(large.begin(), large.end());
			if (large.size() > small.size()) {
				std::pop_heap(large.begin(), large.end());
				small.push_back(-large.back());
				std::push_heap(small.begin(), small.end());
				large.pop_back();
			}
		}
	}

	double findMedian() {
		if (small.size() == large.size()) {
			int x1 = small.front(), x2 = -large.front();
			return x1 + double(x2 - x1) / 2;
		}
		else return small.front();
	}
private:
	std::vector<int> small, large;
};

#endif

#ifdef __SOLUTION_2

// Binary Search Tree: O(logn), O(logn), 148ms
// Each node keeps track #nodes in its left child
class MedianFinder {
public:
    MedianFinder() : tree(nullptr), total(0) {}
    void addNum(int num) {
        total++;
        if (tree == nullptr) {
            tree = new TreeNode(num);
            return;
        }
        auto node = tree;
        while (true) {
            if (num <= node->val) {
                node->leftCount++;
                if (node->left == nullptr) {
                    node->left = new TreeNode(num);
                    return;
                }
                else node = node->left;
            }
            else {
                if (node->right == nullptr) {
                    node->right = new TreeNode(num);
                    return;
                }
                else node = node->right;
            }
        }
    }
    double findMedian() {
        if (total == 0) return 0;
        if (total % 2 == 1) return findNth(total / 2 + 1);
        else return (findNth(total / 2) + findNth(total / 2 + 1)) * 0.5;
    }
private:
    struct TreeNode {
        TreeNode *left, *right;
        int leftCount, val;
        TreeNode(int val) : left(nullptr), right(nullptr), val(val), leftCount(0) {}
    };
    int findNth(int n) {
        auto node = tree;
        int count = 0;
        while (true) {
            auto newCount = count + node->leftCount + 1;
            if (newCount == n) return node->val;
            else if (newCount < n) {
                count = newCount;
                node = node->right;
            }
            else {
                node = node->left;
            }
        }
    }
    TreeNode* tree;
    int total;
};

#endif

int main() {
	auto sol = std::make_unique<MedianFinder>();
	sol->addNum(1);
	sol->addNum(2);
	assert(sol->findMedian() == 1.5);
	sol->addNum(3);
	assert(sol->findMedian() == 2);
    sol->addNum(-1);
    assert(sol->findMedian() == 1.5);
    sol->addNum(0);
    assert(sol->findMedian() == 1);
}
