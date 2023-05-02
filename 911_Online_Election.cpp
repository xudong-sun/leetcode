/*
You are given two integer arrays persons and times. In an election, the ith vote was cast for persons[i] at time times[i].

For each query at a time t, find the person that was leading the election at time t. Votes cast at time t will count towards our query. In the case of a tie, the most recent vote (among tied candidates) wins.

Implement the TopVotedCandidate class:

TopVotedCandidate(int[] persons, int[] times) Initializes the object with the persons and times arrays.
int q(int t) Returns the number of the person that was leading the election at time t according to the mentioned rules.


Example 1:

Input
["TopVotedCandidate", "q", "q", "q", "q", "q", "q"]
[[[0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]], [3], [12], [25], [15], [24], [8]]
Output
[null, 0, 1, 1, 0, 0, 1]

Explanation
TopVotedCandidate topVotedCandidate = new TopVotedCandidate([0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]);
topVotedCandidate.q(3); // return 0, At time 3, the votes are [0], and 0 is leading.
topVotedCandidate.q(12); // return 1, At time 12, the votes are [0,1,1], and 1 is leading.
topVotedCandidate.q(25); // return 1, At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
topVotedCandidate.q(15); // return 0
topVotedCandidate.q(24); // return 0
topVotedCandidate.q(8); // return 1
*/


#include "essentials.h"

class TopVotedCandidate {
public:
  TopVotedCandidate(const std::vector<int>& persons, const std::vector<int>& times) {
    std::unordered_map<int, int> count;
    int winner = -1;
    count[-1] = -1;
    for (int i = 0; i < int(persons.size()); i++) {
      int person = persons[i];
      int time = times[i];
      count[person]++;
      if (person != winner && count[person] >= count[winner]) {
        winner = person;
        winner_.push_back({time, winner});
      }
    }
  }

  int q(int t) const {
    if (t >= winner_.back().first) {
      return winner_.back().second;
    }
    int l = 0, r = winner_.size() - 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (winner_[m].first <= t && t < winner_[m + 1].first) {
        return winner_[m].second;
      }
      if (winner_[m].first > t) {
        r = m;
      } else if (t >= winner_[m + 1].first) {
        l = m + 1;
      }
    }
    return -1;
  }
private:
  std::vector<std::pair<int, int>> winner_;
};

int main() {
  std::vector<int> persons = {0, 1, 1, 0, 0, 1, 0};
  std::vector<int> times = {0, 5, 10, 15, 20, 25, 30};
  auto sol = std::make_unique<TopVotedCandidate>(persons, times);
  assert(sol->q(3) == 0);
  assert(sol->q(12) == 1);
  assert(sol->q(25) == 1);
  assert(sol->q(15) == 0);
  assert(sol->q(24) == 0);
  assert(sol->q(8) == 1);
}

