'''
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
'''


class MinStack(object):
    def __init__(self):
        self._minvalues = []
        self._stack = []

    def push(self, x):
        self._stack.append(x)
        self._minvalues.append(x if len(self._minvalues) == 0 else min(self._minvalues[-1], x))

    def pop(self):
        self._stack.pop()
        self._minvalues.pop()

    def top(self):
        return self._stack[-1]

    def getMin(self):
        return self._minvalues[-1]

if __name__ == '__main__':
    minStack = MinStack()
    minStack.push(-2)
    minStack.push(0)
    minStack.push(-3)
    print minStack.getMin()
    minStack.pop()
    print minStack.top()
    print minStack.getMin()

