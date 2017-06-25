/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

#include "essentials.h"

class MyQueue {
public:
	MyQueue() : stack(std::stack<int>()) {}

	void push(int x) {
		auto tmp = std::stack<int>();
		while (stack.size() > 0) {
			tmp.push(stack.top());
			stack.pop();
		}
		stack.push(x);
		while (tmp.size() > 0) {
			stack.push(tmp.top());
			tmp.pop();
		}
	}

	int pop() {
		int x = stack.top();
		stack.pop();
		return x;
	}

	int peek() {
		return stack.top();
	}

	bool empty() {
		return stack.empty();
	}

private:
	std::stack<int> stack;
};

int main() {
	auto queue = new MyQueue();
	queue->push(1);
	queue->push(2);
	queue->push(3);
	assert(queue->peek() == 1);
	assert(queue->pop() == 1);
	assert(queue->pop() == 2);
	queue->push(4);
	assert(queue->pop() == 3);
	assert(!queue->empty());
	assert(queue->pop() == 4);
	assert(queue->empty());
	delete queue;
	commons::pause();
}