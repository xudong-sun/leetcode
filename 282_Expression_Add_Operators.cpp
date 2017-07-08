/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples:
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

#include "essentials.h"

// check out 227_Basic_Calculator_II.py for algorithm to calculate expressions with +-*/
class Solution {
public:
	std::vector<std::string> addOperators(std::string num, int target) {
		this->num = num;
		this->target = target;
		result.clear();
		if (num.size() == 0) return result;
		if (num[0] == '0') dfs(0, "0", 0, 0);
		else {
			std::string str = "";
			long long val = 0;
			for (size_t i = 0; i < num.size(); i++) {
				str += num[i];
				val = 10 * val + num[i] - '0';
				dfs(i, str, 0, val);
			}
		}
		return result;
	}
private:
	void dfs(size_t pos, std::string resultStr, long long resultVal, long long nextVal) {
		if (pos == num.size() - 1) {
			if (resultVal + nextVal == target) result.push_back(resultStr);
			return;
		}
		if (num[pos + 1] == '0') {
			dfs(pos + 1, resultStr + "+0", resultVal + nextVal, 0);
			dfs(pos + 1, resultStr + "-0", resultVal + nextVal, 0);
			dfs(pos + 1, resultStr + "*0", resultVal, 0);
		}
		else {
			long long curOperand = 0;
			std::string curStr = "";
			for (size_t i = pos + 1; i < num.size(); i++) {
				curStr += num[i];
				curOperand = 10 * curOperand + num[i] - '0';
				dfs(i, resultStr + '+' + curStr, resultVal + nextVal, curOperand);
				dfs(i, resultStr + '-' + curStr, resultVal + nextVal, -curOperand);
				dfs(i, resultStr + '*' + curStr, resultVal, nextVal * curOperand);
			}
		}
	}
	std::string num;
	int target;
	std::vector<std::string> result;
};

int main() {
	auto sol = std::make_unique<Solution>();
	commons::print(sol->addOperators("123", 6)); // ["1+2+3", "1*2*3"]
	commons::print(sol->addOperators("232", 8)); // ["2*3+2", "2+3*2"]
	commons::print(sol->addOperators("105", 5)); // ["1*0+5", "10-5"]
	commons::print(sol->addOperators("00", 0));  // ["0+0", "0-0", "0*0"]
	commons::print(sol->addOperators("3456237490", 9191)); // []
	commons::print(sol->addOperators("1009", 9));
	commons::pause();
}