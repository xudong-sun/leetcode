/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

#include "essentials.h"

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> nums{ n };
        while (n != 1) {
            n = f(n);
            if (nums.find(n) != nums.end()) return false;
            nums.insert(n);
        }
        return true;
    }

private:
    int f(int n) {
        int z = 0, m;
        while (n > 0) {
            m = n % 10;
            z += m*m;
            n /= 10;
        }
        return z;
    }
};

int main() {
    auto sol = new Solution();
    std::cout << sol->isHappy(19) << std::endl;
    delete sol;
    commons::pause();
}
