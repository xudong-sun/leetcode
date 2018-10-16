/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
*/

#include "essentials.h"

// union find

class Solution {
public:
  std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
    int n = edges.size();
    std::vector<int> head(n, 0);
    std::iota(head.begin(), head.end(), 0);
    for (auto& p : edges) {
      if (merge(head, p[0]-1, p[1]-1) == false) return p;
    }
  }
private:
  bool merge(std::vector<int>& head, int x, int y) {
    int hx = findHead(head, x);
    int hy = findHead(head, y);
    if (hx == hy) return false;
    else {
      head[hx] = hy;
      return true;
    }
  }
  int findHead(std::vector<int>& head, int x) {
    if (head[x] == x) return x;
    else {
      int h = findHead(head, head[x]);
      head[x] = h;
      return h;
    }
  }
};

int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<std::vector<int>> edges = {{1,2},{1,3},{2,3}};
  std::vector<int> ans = {2,3};
  assert(sol->findRedundantConnection(edges) == ans);
  edges = {{1,2},{2,3},{3,4},{1,4},{4,5}};
  ans = {1,4};
  assert(sol->findRedundantConnection(edges) == ans);
  edges = {{3,7},{1,4},{2,8},{1,6},{7,9},{6,10},{1,7},{2,3},{8,9},{5,9}};
  ans = {8,9};
  assert(sol->findRedundantConnection(edges) == ans);
}


