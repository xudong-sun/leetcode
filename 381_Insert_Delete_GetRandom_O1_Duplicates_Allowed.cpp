/*
Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
Example:

// Init an empty collection.
// RandomizedCollection collection = new RandomizedCollection();
//
// // Inserts 1 to the collection. Returns true as the collection did not contain 1.
// collection.insert(1);
//
// // Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
// collection.insert(1);
//
// // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
// collection.insert(2);
//
// // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
// collection.getRandom();
//
// // Removes 1 from the collection, returns true. Collection now contains [1,2].
// collection.remove(1);
//
// // getRandom should return 1 and 2 both equally likely.
// collection.getRandom();
*/


#include "essentials.h"

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        num2pos[val].insert(nums.size());
        nums.push_back(val);
        return num2pos[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (num2pos.find(val) == num2pos.cend()) return false;
        size_t i = *(num2pos[val].begin());
        num2pos[val].erase(i);
        num2pos[nums.back()].insert(i);
        num2pos[nums.back()].erase(nums.size() - 1);
        if (num2pos[val].size() == 0) num2pos.erase(val);
        std::swap(nums[i], nums.back());
        nums.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % (nums.size())];
    }

private:
    std::unordered_map<int, std::unordered_set<size_t>> num2pos;
    std::vector<int> nums;
};


int main() {
    auto collection = std::make_unique<RandomizedCollection>();
    assert(collection->insert(1));
    assert(!collection->insert(1));
    assert(collection->insert(2));
    std::unordered_map<int, int> count;
    for (int i = 0; i < 1000; i++) count[collection->getRandom()]++;
    commons::print(count); // [1,1,2]
    assert(collection->remove(1));
    assert(!collection->remove(0));
    count.clear();
    for (int i = 0; i < 1000; i++) count[collection->getRandom()]++;
    commons::print(count); // [1,2]
    assert(collection->remove(2));
    assert(!collection->remove(2));
    count.clear();
    for (int i = 0; i < 1000; i++) count[collection->getRandom()]++;
    commons::print(count); // [1]
    auto tmp = std::make_unique<RandomizedCollection>();
    tmp->insert(1);
    tmp->insert(1);
    tmp->insert(2);
    tmp->insert(1);
    tmp->insert(2);
    tmp->insert(2);
    tmp->remove(1);
    tmp->remove(2);
    tmp->remove(2);
    tmp->remove(2);
    count.clear();
    for (int i = 0; i < 1000; i++) count[tmp->getRandom()]++;
    commons::print(count);
}

