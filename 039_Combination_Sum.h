/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
	{
		sort(candidates.begin(), candidates.end());
		vector<int> clear;
		search(candidates, clear, target, 0);
		return ans;
	}
private:
	void search(vector<int>& candidates, vector<int>& result, int target, int index)
	{
		if (index == candidates.size())
		{
			if (target == 0) ans.push_back(result);
			return;
		}
		int x = candidates[index];
		do
		{
			search(candidates, result, target, index + 1);
			target -= x; result.push_back(x);
		} while (target >= 0);
		while (!result.empty() && result.back() == x) result.pop_back();
	}
	vector<vector<int>> ans;
};