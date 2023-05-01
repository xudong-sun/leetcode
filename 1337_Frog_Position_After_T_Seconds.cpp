/*
Given an undirected tree consisting of n vertices numbered from 1 to n. A frog starts jumping from the vertex 1. In one second, the frog jumps from its current vertex to another unvisited vertex if they are directly connected. The frog can not jump back to a visited vertex. In case the frog can jump to several vertices it jumps randomly to one of them with the same probability, otherwise, when the frog can not jump to any unvisited vertex it jumps forever on the same vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [x, y] means that exists an edge connecting directly the vertices x and y.

Return the probability that after t seconds the frog is on the vertex "target".

1 <= n <= 100
edges.length == n-1
edges[i].length == 2
1 <= edges[i][0], edges[i][1] <= n
1 <= t <= 50
1 <= target <= n
Answers within 10^-5 of the actual value will be accepted as correct.
*/

#include "essentials.h"

class Solution {
public:
  double frogPosition(int n, const std::vector<std::vector<int>>& edges, int t, int target) {
    // convert to adjacency matrix
    std::unordered_map<int, std::unordered_set<int>> g;
    for (const auto& edge : edges) {
      g[edge[0]].insert(edge[1]);
      g[edge[1]].insert(edge[0]);
    }
    // BFS
    std::vector<bool> visited(n + 1, false);
    std::deque<std::pair<int, double>> q; // {vertex, prob}
    int time = 0;
    q.emplace_back(1, 1);
    visited[1] = true;
    while (!(q.empty()) && time <= t) {
      std::deque<std::pair<int, double>> next_q;
      for (const auto& p : q) {
        int node = p.first;
        double prob = p.second;
        const auto& neighbors = g[node];
        int unvisited_count = std::count_if(neighbors.begin(), neighbors.end(),
            [visited](int x) {return !(visited.at(x));});
        if (node == target) {
          if (time == t) return prob; // normal termination
          if (unvisited_count == 0) return prob; // follow-up (optimization)
          return 0; // follow-up (optimization)
        }
        for (int x : neighbors) {
          if (!visited[x]) {
            next_q.emplace_back(x, prob / unvisited_count);
            visited[x] = true;
          }
        }
      }
      q = std::move(next_q);
      time++;
    }
    return 0;
  }
};

int main() {
  Solution* sol = new Solution();
  std::cout << sol->frogPosition(3, {{1,2},{1,3}}, 1, 2) << std::endl;
  std::cout << sol->frogPosition(7, {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}}, 2, 4) << std::endl;
  std::cout << sol->frogPosition(7, {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}}, 20, 6) << std::endl;
  std::cout << sol->frogPosition(7, {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}}, 1, 6) << std::endl;
  std::cout << sol->frogPosition(8, {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5},{4,8}}, 2, 4) << std::endl;
}

