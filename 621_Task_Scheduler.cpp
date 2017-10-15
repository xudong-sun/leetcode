/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/


#include "essentials.h"

#define __SOLUTION_2

#ifdef __SOLUTION_1
// greedy, O(n), 132ms
class Solution {
public:
    int leastInterval(const std::vector<char>& tasks, int n) {
        std::vector<int> count(26, 0);
        for (auto ch : tasks) count[ch - 'A']++;
        std::vector<int> cooldown(26, 0);
        int time = 0, task_left = tasks.size();
        while (task_left > 0) {
            int argm = -1, m = 0;
            for (int i = 0; i < 26; i++) 
                if (cooldown[i] > 0) cooldown[i]--;
                else if (count[i] > m) {
                    argm = i; m = count[i];
                }
            if (argm != -1) { count[argm]--; task_left--; cooldown[argm] = n; }
            time++;
        }
        return time;
    }
};

#endif

#ifdef __SOLUTION_2

// greedy, O(n), calculate result directly, 66ms
class Solution {
public:
    int leastInterval(const std::vector<char>& tasks, int n) {
        if (tasks.size() == 0) return 0;
        std::vector<int> count(26, 0);
        for (auto ch : tasks) count[ch - 'A']++;
        std::sort(count.begin(), count.end());
        int j = 24;
        while (j >= 0 && count[j] == count[25]) j--;
        return std::max((n+1) * (count[25]-1) + (25-j), static_cast<int>(tasks.size()));
    }
};

#endif

int main() {
    auto sol = std::make_unique<Solution>();
    assert(sol->leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 2) == 8);
    assert(sol->leastInterval({'A', 'B', 'C', 'A', 'A'}, 2) == 7);
    assert(sol->leastInterval({'A', 'B', 'C', 'A', 'A'}, 1) == 5);
    assert(sol->leastInterval({'A', 'A', 'A'}, 0) == 3);
    assert(sol->leastInterval({'A', 'A', 'A'}, 1) == 5);
    assert(sol->leastInterval({'A'}, 3) == 1);
    assert(sol->leastInterval({}, 3) == 0);
}

