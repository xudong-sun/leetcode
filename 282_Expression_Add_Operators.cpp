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

#define __SOLUTION_2

#ifdef __SOLUTION_1
// check out 227_Basic_Calculator_II.py for algorithm to calculate expressions with +-*/
// 109ms
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

#endif

#ifdef __SOLUTION_2
// first bottom-up DP to take care of *
// then DP to take care of +-
// 695ms
class Solution {
public:
	std::vector<std::string> addOperators(const std::string& num, int target) {
        calcMultiplies(num);
        std::map<size_t, std::map<long long, std::vector<std::string>>> result;
        for (size_t i = 0; i < num.size(); i++) {
            result[i] = multiplyResult[0][i];
            for (size_t j = 0; j < i; j++) { // add / minus two operands
                for (auto firstOp : result[j])
                    for (auto secondOp : multiplyResult[j+1][i]) {
                        long long val = firstOp.first + secondOp.first;
                        std::vector<std::string> strs;
                        for (auto firstStr : firstOp.second)
                            for (auto secondStr : secondOp.second)
                                strs.push_back(firstStr + '+' + secondStr);
                        std::copy(strs.begin(), strs.end(), std::back_inserter(result[i][val]));
                        val = firstOp.first - secondOp.first;
                        strs.clear();
                        for (auto firstStr : firstOp.second)
                            for (auto secondStr : secondOp.second)
                                strs.push_back(firstStr + '-' + secondStr);
                        std::copy(strs.begin(), strs.end(), std::back_inserter(result[i][val]));
                    }
            }
        }
        return result[num.size() - 1][target];
	}
private:
    std::vector<std::vector<std::pair<long long, std::string>>> directNum;
    std::vector<std::vector<std::map<long long, std::vector<std::string>>>> multiplyResult;
    void calcMultiplies(const std::string& num) {
        // initialize
        directNum.clear();
        multiplyResult.clear();
        for (size_t i = 0; i < num.size(); i++) {
            std::vector<std::pair<long long, std::string>> tmp;
            for (size_t j = 0; j < num.size(); j++) {
                tmp.emplace_back(0, "0");
            }
            directNum.push_back(tmp);
        }
        for (size_t i = 0; i < num.size(); i++) {
            std::vector<std::map<long long, std::vector<std::string>>> tmp;
            for (size_t j = 0; j < num.size(); j++) {
                tmp.emplace_back();
            }
            multiplyResult.push_back(tmp);
        }
        // calc directNum
        for (size_t i = 0; i < num.size(); i++)
            for (size_t j = i; j < num.size(); j++)
                if (i == j || num[i] != '0') {
                    std::string str = num.substr(i, j - i + 1);
                    long long val = stoll(str);
                    directNum[i][j] = {val, str};
                }
        // calc multiplyResult
        for (size_t l = 1; l <= num.size(); l++) {
            for (size_t i = 0; i <= num.size() - l; i++) {
                size_t j = i + l - 1;
                if (l == 1 || num[i] != '0') { // number as a whole
                    auto this_num = directNum[i][j];
                    multiplyResult[i][j][this_num.first].push_back(this_num.second);
                }
                // multiply two parts
                for (size_t k = i; k < j; k++) {
                    if (num[k+1] != '0' || k == j - 1) {
                        auto secondNum = directNum[k+1][j];
                        for (auto firstOp : multiplyResult[i][k]) {
                            long long val = firstOp.first * secondNum.first;
                            std::vector<std::string> strs;
                            for (auto firstStr : firstOp.second)
                                strs.push_back(firstStr + '*' + secondNum.second);
                            std::copy(strs.begin(), strs.end(), std::back_inserter(multiplyResult[i][j][val]));
                        }
                    }
                }
            }
        }
    }
};

#endif


int main() {
	auto sol = std::make_unique<Solution>();
	commons::print(sol->addOperators("123", 6)); // ["1+2+3", "1*2*3"]
	commons::print(sol->addOperators("232", 8)); // ["2*3+2", "2+3*2"]
	commons::print(sol->addOperators("105", 5)); // ["1*0+5", "10-5"]
	commons::print(sol->addOperators("00", 0));  // ["0+0", "0-0", "0*0"]
	commons::print(sol->addOperators("3456237490", 9191)); // []
	commons::print(sol->addOperators("1009", 9));
}
