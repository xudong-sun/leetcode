/*
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
  [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
  [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.
*/

#include "essentials.h"

// union find, O(n^2)
class Solution {
public:
    int findCircleNum(const std::vector<std::vector<int>>& M) {
        int n = M.size();
        if (n == 0) return 0;
        head.clear(); rank.clear();
        for (int i = 0; i < n; i++) {
            head.push_back(i); rank.push_back(0);
        }
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (M[i][j]) merge(i, j);
        std::unordered_set<int> heads;
        for (int i = 0; i < n; i++) heads.insert(find(i));
        return heads.size();
    }
private:
    std::vector<int> head, rank;
    int find(int node) {
        if (head[node] != node) head[node] = find(head[node]);
        return head[node];
    }
    void merge(int x1, int x2) {
        int head1 = find(x1), head2 = find(x2);
        if (rank[head1] < rank[head2]) head[head1] = head2;
        else if (rank[head2] > rank[head1]) head[head2] = head1;
        else { head[head1] = head2; rank[head2]++; }
    }
};

int main() {
    auto sol = std::make_unique<Solution>();
    assert(sol->findCircleNum({{1,1,0},{1,1,0},{0,0,1}}) == 2);
    assert(sol->findCircleNum({{1,1,0},{1,1,1},{0,1,1}}) == 1);
    assert(sol->findCircleNum({{1}}) == 1);
    assert(sol->findCircleNum({}) == 0);
}

