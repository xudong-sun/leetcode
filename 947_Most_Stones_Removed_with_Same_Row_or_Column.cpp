/*
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.



Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.


Constraints:

1 <= stones.length <= 1000
0 <= xi, yi <= 10^4
No two stones are at the same coordinate point.
*/


#include <essentials.h>

// Solution 1: union find
class Solution1 {
public:
  int removeStones(const std::vector<std::vector<int>>& stones) {
    int n = stones.size();
    std::unordered_map<int, std::vector<int>> stone_ids_by_row, stone_ids_by_column;
    for (int i = 0; i < n; i++) {
      int x = stones[i][0], y = stones[i][1];
      stone_ids_by_row[x].push_back(i);
      stone_ids_by_column[y].push_back(i);
    }
    std::vector<int> head(n, 0);
    for (int i = 0; i < n; i++) head[i] = i;
    for (const auto& p : stone_ids_by_row) {
      const auto& ids = p.second;
      for (size_t i = 1; i < ids.size(); i++) merge(ids[0], ids[i], head);
    }
    for (const auto& p : stone_ids_by_column) {
      const auto& ids= p.second;
      for (size_t i = 1; i < ids.size(); i++) merge(ids[0], ids[i], head);
    }
    std::unordered_set<int> heads;
    for (int i = 0; i < n; i++) heads.insert(getHead(i, head));
    return n - heads.size();
  }
private:
  int getHead(int x, std::vector<int>& head) {
    if (head[x] == x) return x;
    head[x] = getHead(head[x], head);
    return head[x];
  }
  void merge(int x, int y, std::vector<int>& head) {
    int head_x = getHead(x, head);
    int head_y = getHead(y, head);
    if (head_x != head_y) head[head_y] = head_x;
  }
};

// Solution 2: BFS
class Solution2 {
public:
  int removeStones(const std::vector<std::vector<int>>& stones) {
    int n = stones.size();
    std::unordered_map<int, std::vector<int>> stone_ids_by_row, stone_ids_by_column;
    for (int i = 0; i < n; i++) {
      int x = stones[i][0], y = stones[i][1];
      stone_ids_by_row[x].push_back(i);
      stone_ids_by_column[y].push_back(i);
    }
    std::unordered_set<int> remaining;
    for (int i = 0; i < n; i++) remaining.insert(i);
    int groups = 0;
    while (remaining.size() > 0) {
      groups++;
      int start = *(remaining.begin());
      std::queue<int> q;
      q.push(start);
      remaining.erase(start);
      while (!q.empty()) {
        int index = q.front();
        q.pop();
        int row = stones[index][0];
        int column = stones[index][1];
        for (auto i : stone_ids_by_row[row]) {
          if (remaining.find(i) != remaining.end()) {
            q.push(i);
            remaining.erase(i);
          }
        }
        for (auto i : stone_ids_by_column[column]) {
          if (remaining.find(i) != remaining.end()) {
            q.push(i);
            remaining.erase(i);
          }
        }
      }
    }
    return n - groups;
  }
};

// Solution 3: DFS
class Solution3 {
public:
  int removeStones(const std::vector<std::vector<int>>& stones) {
    int n = stones.size();
    stone_ids_by_row.clear();
    stone_ids_by_column.clear();
    for (int i = 0; i < n; i++) {
      int x = stones[i][0], y = stones[i][1];
      stone_ids_by_row[x].push_back(i);
      stone_ids_by_column[y].push_back(i);
    }
    std::unordered_set<int> remaining;
    for (int i = 0; i < n; i++) remaining.insert(i);
    int groups = 0;
    while (remaining.size() > 0) {
      groups++;
      int start = *(remaining.begin());
      remaining.erase(start);
      DFS(start, remaining, stones);
    }
    return n - groups;
  }
private:
  void DFS(int index, std::unordered_set<int>& remaining, const std::vector<std::vector<int>>& stones) {
    int row = stones[index][0];
    int column = stones[index][1];
    for (auto i : stone_ids_by_row[row]) {
      if (remaining.find(i) != remaining.end()) {
        remaining.erase(i);
        DFS(i, remaining, stones);
      }
    }
    for (auto i : stone_ids_by_column[column]) {
      if (remaining.find(i) != remaining.end()) {
        remaining.erase(i);
        DFS(i, remaining, stones);
      }
    }
  }

  std::unordered_map<int, std::vector<int>> stone_ids_by_row, stone_ids_by_column;
};


int main() {
  auto sol = std::make_unique<Solution3>();
  std::vector<std::vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
  assert(sol->removeStones(stones) == 5);
  stones = {{0,0},{0,2},{1,1},{2,0},{2,2}};
  assert(sol->removeStones(stones) == 3);
  stones = {{0,0}};
  assert(sol->removeStones(stones) == 0);
}


