/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/

#include "essentials.h"

class Solution {
public:
	std::vector<int> diffWaysToCompute(std::string input) {
		if (calculated_results.find(input) != calculated_results.end()) return calculated_results[input];
		std::vector<int> result;
		for (size_t i = 0; i < input.size(); i++) {
			auto ch = input[i];
			if (ch == '+' || ch == '-' || ch == '*') {
				auto result1 = diffWaysToCompute(input.substr(0, i));
				auto result2 = diffWaysToCompute(input.substr(i + 1));
				for (auto a : result1)
					for (auto b : result2)
						result.push_back(ch == '+' ? a + b : (ch == '-' ? a - b : a*b));
			}
		}
		// if `input` contains only digits
		if (result.empty()) result.push_back(atoi(input.c_str()));
		calculated_results[input] = result;
		return result;
	}
private:
	static std::unordered_map<std::string, std::vector<int>> calculated_results;
};
std::unordered_map<std::string, std::vector<int>> Solution::calculated_results = {};

int main() {
	auto sol = std::make_unique<Solution>();
	commons::print(sol->diffWaysToCompute("2-1-1"));
	commons::print(sol->diffWaysToCompute("2*3-4*5"));
	commons::print(sol->diffWaysToCompute("-12"));
	commons::pause();
}