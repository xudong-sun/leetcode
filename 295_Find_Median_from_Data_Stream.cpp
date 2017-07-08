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

// use two heaps. Heap 1 stores the smaller half; heap 2 stores the larger half
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

int main() {
	auto sol = std::make_unique<MedianFinder>();
	sol->addNum(1);
	sol->addNum(2);
	assert(sol->findMedian() == 1.5);
	sol->addNum(3);
	assert(sol->findMedian() == 2);
}