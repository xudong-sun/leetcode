/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/


#include "essentials.h"

// My first solution was O(n^2 log n)
// Key point: find each entry of the result one by one
// 1. sort by {h: low to high; k: low to high}
// 2. find the first pair that fits to the back of the current queue, push it to the back, repeat n times
// we can use binary search tree (315_Count_of_Smaller_Numbers_After_Self) to quickly find how many people are taller in the current queue, at cost O(logn) for each person
//
// Here is the second solution, O(n^2)
// Key point: start with the tallest group
// 1. sort by {h: high to low; k: low to high}
// 2. insert the tallest group to the queue

class Solution {
public:
    std::vector<std::pair<int, int>> reconstructQueue(std::vector<std::pair<int, int>>& people) {
        auto comp = [](std::pair<int, int> x, std::pair<int, int> y) { return x.first > y.first || (x.first == y.first && x.second < y.second); };
        std::sort(people.begin(), people.end(), comp);
        std::vector<std::pair<int, int>> res;
        for (auto person : people) res.insert(res.cbegin() + person.second, person);
        return res;
    }
};


int main() {
    auto sol = std::make_unique<Solution>();
    std::vector<std::pair<int, int>> people{{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    commons::print(sol->reconstructQueue(people)); // [<5,0>, <7,0>, <5,2>, <6,1>, <4,4>, <7,1>]
}

