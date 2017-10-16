/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

#include "essentials.h"

class Solution {
public:
    std::vector<int> intersect(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        std::unordered_multiset<int> ss(nums1.cbegin(), nums1.cend());
        std::vector<int> result;
        for (auto n : nums2) {
            auto p = ss.find(n);
            if (p != ss.cend()) {
                result.push_back(n);
                ss.erase(p);
            }
        }
        return result;
    }
};


int main() {
    auto sol = std::make_unique<Solution>();
    commons::print(sol->intersect({1,2,2,1}, {2,2})); // 2,2
    commons::print(sol->intersect({1,2,3,4,5}, {5,4,3,2,1})); // 1,2,3,4,5
    commons::print(sol->intersect({1}, {1,2,3,1})); // 1
    commons::print(sol->intersect({}, {1,2,3})); // {}
    commons::print(sol->intersect({1,1,4}, {})); // {}
}

