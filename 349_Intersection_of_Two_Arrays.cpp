/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

#include "essentials.h"

class Solution {
public:
    std::vector<int> intersection(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        std::unordered_set<int> ss(nums1.cbegin(), nums1.cend());
        std::unordered_set<int> result;
        for (auto n : nums2) {
            if (ss.find(n) != ss.cend()) result.insert(n);
        }
        return std::vector<int>(result.cbegin(), result.cend());
    }
};

int main() {
    auto sol = std::make_unique<Solution>();
    commons::print(sol->intersection({1,2,2,1}, {2,2})); // 2
    commons::print(sol->intersection({1,2,3,4,5}, {5,4,3,2,1})); // 1,2,3,4,5
    commons::print(sol->intersection({1}, {1,2,3,1})); // 1
    commons::print(sol->intersection({}, {1,2,3})); // {}
    commons::print(sol->intersection({1,1,4}, {})); // {}
}
