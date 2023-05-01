/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.
*/


#include "essentials.h"

class Solution {
public:
  int totalFruit(const std::vector<int>& fruits) {
    int type1 = fruits[0], type2 = -1;
    int start1 = 0, start2 = 0;
    int pos1 = 0, pos2 = 0;
    int res = 0;
    for (int i = 1; i < int(fruits.size()); i++) {
      int type = fruits[i];
      if (type == type1) {
        pos1 = i;
      }
      else if (type2 == -1) {
        type2 = type;
        start2 = i;
        pos2 = i;
      }
      else if (type == type2) {
        pos2 = i;
      } else {
        int new_res = i - start1;
        if (new_res > res) res = new_res;
        int last_type = fruits[i - 1];
        if (last_type == type1) {
          start1 = pos2 + 1;
          pos1 = i - 1;
        } else {
          type1 = type2;
          start1 = pos1 + 1;
          pos1 = i - 1;
        }
        type2 = type;
        start2 = i;
        pos2 = i;
      }
    }
    int new_res = fruits.size() - start1;
    if (new_res > res) res = new_res;
    return res;
  }
};


int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<int> fruits = {1, 2, 1};
  assert(sol->totalFruit(fruits) == 3);
  fruits = {0, 1, 2, 2};
  assert(sol->totalFruit(fruits) == 3);
  fruits = {1, 2, 3, 2, 2};
  assert(sol->totalFruit(fruits) == 4);
  fruits = {1, 2, 1, 2, 1, 3, 1, 3, 3, 3, 1, 4, 1};
  assert(sol->totalFruit(fruits) == 7);
  fruits = {1, 2, 1, 1, 1, 3, 3, 1, 2, 1, 1};
  assert(sol->totalFruit(fruits) == 6);
}

