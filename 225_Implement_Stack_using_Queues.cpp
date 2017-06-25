/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

#include "essentials.h"

class MyStack {
public:
	MyStack() : queue(std::queue<int>()) {}

	void push(int x) {
		queue.push(x);
		for (size_t i = 0; i < queue.size() - 1; i++) {
			queue.push(queue.front());
			queue.pop();
		}
	}

	int pop() {
		int x = queue.front();
		queue.pop();
		return x;
	}

	int top() {
		return queue.front();
	}

	bool empty() {
		return queue.empty();
	}

private:
	std::queue<int> queue;
};

int main() {
	auto stack = new MyStack();
	stack->push(1);
	stack->push(2);
	assert(stack->top() == 2);
	assert(stack->pop() == 2);
	assert(stack->top() == 1);
	stack->push(3);
	assert(stack->pop() == 3);
	assert(!stack->empty());
	assert(stack->pop() == 1);
	assert(stack->empty());
	delete stack;
}