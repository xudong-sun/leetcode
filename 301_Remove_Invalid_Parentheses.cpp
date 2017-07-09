/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/

#include "essentials.h"

// 1. remove invalid ')'s
// 2. reverse string, ')' <-> '('
// 3. remove invalid ')'s
// 4. reverse string, ')' <-> '('
class Solution {
public:
	std::vector<std::string> removeInvalidParentheses(std::string s) {
		std::vector<std::string> result;
		auto res1 = removeCloseParentheses(s);
		for (auto res : res1) {
			auto res2 = removeCloseParentheses(reverse(res));
			for (auto r : res2) result.push_back(reverse(r));
		}
		return result;
	}
private:
	// a state used for bfs
	// s: current string
	// next_remove_index: next start index to remove a ')'
	// balance_index: up util this balance_index-1, parentheses count is 0
	struct State {
		std::string s;
		size_t next_remove_index;
		size_t balance_index;
		State(std::string s, size_t next_remove_index, size_t balance_index) :
			s(s), next_remove_index(next_remove_index), balance_index(balance_index) {}
	};
	// remove one ')', only remove at string index [start, end]
	// for sequential ')'s, remove the first one only
	// all generated results will be pushed to the bfs queue
	void removeOneParenthesis(std::string s, size_t start, size_t end) {
		for (size_t p = start; p <= end; p++) {
			if (s[p] == ')' && (p == 0 || s[p - 1] != ')')) queue.push(State(std::string(s).erase(p, 1), p, end));
		}
	}
	// remove invalid ')'s
	// return all possible results
	std::vector<std::string> removeCloseParentheses(std::string s) {
		std::vector<std::string> result;
		queue.push(State(s, 0, 0));
		while (!queue.empty()) {
			auto st = queue.front();
			std::string str = st.s;
			queue.pop();
			int count = 0, i = st.balance_index;
			while (i < str.size()) {
				if (str[i] == '(') count++;
				else if (str[i] == ')') {
					count--;
					if (count < 0) {
						removeOneParenthesis(str, st.next_remove_index, i);
						break;
					}
				}
				i++;
			}
			if (i == str.size()) result.push_back(str);
		}
		return result;
	}
	// reverse a string, ')' <-> '('
	std::string reverse(std::string s) {
		std::reverse(s.begin(), s.end());
		for (size_t i = 0; i < s.size(); i++) {
			if (s[i] == ')') s[i] = '(';
			else if (s[i] == '(') s[i] = ')';
		}
		return s;
	}
	// the bfs queue
	std::queue<State> queue{};
};

int main() {
	auto sol = std::make_unique<Solution>();
	commons::print(sol->removeInvalidParentheses("()())()"));  // ["()()()", "(())()"]
	commons::print(sol->removeInvalidParentheses("(a)())()")); // ["(a)()()", "(a())()"]
	commons::print(sol->removeInvalidParentheses(")("));       // [""]
	commons::print(sol->removeInvalidParentheses("))((()()")); // ["()()", "(())"]
	commons::pause();
}