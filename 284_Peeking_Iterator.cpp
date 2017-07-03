/*
Given an Iterator class interface with methods : next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().

Here is an example.Assume that the iterator is initialized to the beginning of the list : [1, 2, 3].

Call next() gets you 1, the first element in the list.

Now you call peek() and it returns 2, the next element.Calling next() after that still return 2.

You call next() the final time and it returns 3, the last element.Calling hasNext() after that should return false.

Follow up : How would you extend your design to be generic and work with all types, not just integer ?
*/

#include "essentials.h"

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	std::vector<int>::const_iterator it, end;
	std::vector<int> nums;
public:
	Iterator(const std::vector<int>& nums) : nums(nums) {
		it = this->nums.cbegin();
		end = this->nums.cend();
	}
	Iterator(const Iterator& iter) = delete;
	// Returns the next element in the iteration.
	int next() { return *(it++); }
	// Returns true if the iteration has more elements.
	bool hasNext() const { return it != end; }
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const std::vector<int>& nums) : Iterator(nums), hasPeeked(false) {}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if (!hasPeeked) {
			peekValue = Iterator::next();
			hasPeeked = true;
		}
		return peekValue;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if (hasPeeked) {
			hasPeeked = false;
			return peekValue;
		}
		else return Iterator::next();
	}

	bool hasNext() const {
		if (hasPeeked) return true;
		else return Iterator::hasNext();
	}
private:
	int peekValue;
	bool hasPeeked;
};

int main() {
	auto it = std::make_unique<PeekingIterator>(std::vector < int > {1, 2, 3});
	assert(it->next() == 1);
	assert(it->peek() == 2);
	assert(it->peek() == 2);
	assert(it->hasNext());
	assert(it->next() == 2);
	assert(it->hasNext());
	assert(it->next() == 3);
	assert(!it->hasNext());
}