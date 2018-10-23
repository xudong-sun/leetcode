/*
Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation:
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.
Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation:
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.


Note:

graph will have length in range [1, 100].
graph[i] will contain integers in range [0, graph.length - 1].
graph[i] will not contain i or duplicate values.
The graph is undirected: if any element j is in graph[i], then i will be in graph[j].
*/


#include "essentials.h"

// union find

class Solution {
public:
  bool isBipartite(std::vector<std::vector<int>>& graph) {
    std::vector<int> head(graph.size(), 0);
    std::iota(head.begin(), head.end(), 0);
    for (size_t i = 0; i < graph.size(); i++) {
      int hi = findHead(head, i);
      if (graph[i].size() > 0) {
        int j0 = graph[i][0];
        int hj0 = findHead(head, j0);
        if (hi == hj0) return false;
        for (size_t j = 1; j < graph[i].size(); j++) {
          int hj = findHead(head, graph[i][j]);
          if (hi == hj) return false;
          head[hj] = hj0;
        }
      }
    }
    return true;
  }
private:
  int findHead(std::vector<int>& head, int x) {
    if (head[x] == x) return x;
    int h = findHead(head, head[x]);
    head[x] = h;
    return h;
  }
};

int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<std::vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
  assert(sol->isBipartite(graph));
  graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
  assert(!sol->isBipartite(graph));
  graph = {{},{2,3},{1,3},{1,2}};
  assert(!sol->isBipartite(graph));
  graph = {{},{2},{1,3},{2}};
  assert(sol->isBipartite(graph));
  graph = {{1,2},{0,3},{0,3,4},{1,2,5},{2,5},{3,4}};
  assert(sol->isBipartite(graph));
}

