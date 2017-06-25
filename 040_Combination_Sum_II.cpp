/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

#include "essentials.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
	{
		sort(candidates.begin(), candidates.end());
		vector<int> temp;
		combinationSum2(candidates, temp, target, 0);
		return ans;
	}
private:
	void combinationSum2(vector<int>& candidates, vector<int>& result, int target, int index)
	{
		if (index == candidates.size()) return;
		int x = candidates[index];
		if (x > target) return;
		else if (x == target)
		{
			result.push_back(x);
			ans.push_back(result);
			result.pop_back();
			return;
		}
		combinationSum2(candidates, result, target, nextIndex(candidates, index));
		result.push_back(x);
		combinationSum2(candidates, result, target - x, index + 1);
		result.pop_back();
	}
	int nextIndex(vector<int>& candidates, int now)
	{
		int value = candidates[now]; now++;
		int max_index = candidates.size();
		while (now < max_index)
		{
			if (candidates[now] != value) break;
			now++;
		}
		return now;
	}
	vector<vector<int>> ans;
};

int main() {
	Solution* sol = new Solution();
	std::vector<int> vec{ 10, 1, 2, 7, 6, 1, 5 };
	std::cout << sol->combinationSum2(vec, 8) << std::endl;
	commons::pause();
	delete sol;
}