'''
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
'''


class Solution(object):
    def evalRPN(self, tokens):
        stack = []
        for token in tokens:
            if token == '+': stack.append(stack.pop() + stack.pop())
            elif token == '-': stack.append(-stack.pop() + stack.pop())
            elif token == '*': stack.append(stack.pop() * stack.pop())
            elif token == '/': 
                d1, d2 = stack.pop(), stack.pop()
                sign = 1
                if d1 < 0: d1, sign = abs(d1), -sign
                if d2 < 0: d2, sign = abs(d2), -sign
                stack.append(d2 / d1 * sign)
            else: stack.append(int(token))
        return stack[0]

if __name__ == '__main__':
    print Solution().evalRPN(['2', '1', '+', '3', '*'])
    print Solution().evalRPN(['4', '13', '5', '/', '+'])
    print Solution().evalRPN(['1', '2', '-'])
    print Solution().evalRPN(['0'])
    print Solution().evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"])

