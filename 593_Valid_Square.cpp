/*
Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
*/

#include "essentials.h"

// calculate all distances, check if the smallest 4 are the same, and the longer two are the same
class Solution {
public:
    bool validSquare(const std::vector<int>& p1, const std::vector<int>& p2, 
                     const std::vector<int>& p3, const std::vector<int>& p4) {
        std::vector<int> distances {distance(p1, p2), distance(p1, p3), distance(p1, p4),
                    distance(p2, p3), distance(p2, p4), distance(p3, p4)};
        std::sort(distances.begin(), distances.end());
        return distances[0] != 0 && distances[0] == distances[1] && distances[1] == distances[2] &&
            distances[2] == distances[3] && distances[4] == distances[5];
    }
private:
    int distance(const std::vector<int>& p1, const std::vector<int>& p2) {
        int d1 = p1[0] - p2[0], d2 = p1[1] - p2[1];
        return d1 * d1 + d2 * d2;
    }
};


int main() {
    auto sol = std::make_unique<Solution>();
    assert(sol->validSquare({0,0}, {0,1}, {1,0}, {1,1}));
    assert(sol->validSquare({0,0}, {1,1}, {2,0}, {1,-1}));
    assert(!sol->validSquare({0,0}, {0,2}, {1,0}, {1,2}));
    assert(!sol->validSquare({0,0}, {1,1}, {2,2}, {2,0}));
    assert(!sol->validSquare({0,0}, {1,1}, {1,0}, {1,2}));
    assert(!sol->validSquare({0,0}, {0,0}, {0,0}, {0,0}));
}
