/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

/*
Solution:

Starting from station i, where temp[i]>=0. j=i+1, total_gas=temp[i]+temp[j]
if (total_gas>=0) j++; total_gas+=temp[j]; <can go further> else i--; total_gas+=temp[i]; <trace back, starting point must be before i>
if (i==j) return i
*/

#include "essentials.h"

class Solution {
public:
	int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) 
	{
		int n = gas.size();
		if (n == 0) return -1;
		std::vector<int> temp; temp.resize(n);
		int x = 0;
		for (int i = 0; i < n; i++)
		{
			temp[i] = gas[i] - cost[i];
			x += temp[i];
		}
		if (x < 0) return -1;
		if (n == 1) return 0;
		int i = 0; while (temp[i] < 0) i++;
		int j = i; x = temp[i];
		next(j, n); x += temp[j];
		while (i != j)
		{
			if (x >= 0)
			{
				next(j, n); x += temp[j];
			}
			else
			{
				last(i, n); x += temp[i];
			}
		}
		return i;
	}
private:
	void next(int &x, const int &n)
	{
		x++; if (x == n) x = 0;
	}
	void last(int &x, const int &n)
	{
		x--; if (x < 0) x = n - 1;
	}
};

int main() {
	Solution* sol = new Solution();
	std::vector<int> gas{ 0, 0, 3 };
	std::vector<int> cost{ 1, 1, 1 };
	std::cout << sol->canCompleteCircuit(gas, cost) << std::endl;
	delete sol;
	commons::pause();
}