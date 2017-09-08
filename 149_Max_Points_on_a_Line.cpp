/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

#include "essentials.h"

struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};


// For any two points p_i and p_i+1, consider a third point p_i+2, if the slope of (p_i, p_i+1) and (p_i, p_i+2) are the same, then they are on the same line.
// Each slope is a rational number and can be represented by a pair of integers.
// O(n^2)
class Solution {
public:
    int maxPoints(const std::vector<Point>& points) {
        int ans = 0;
        std::pair<int, int> origin{0, 0};
        for (size_t i = 0; i < points.size(); i++) {
            std::map<std::pair<int, int>, int> count;
            count[origin] = 1; // number of overlapping points at p_i
            for (size_t j = i + 1; j < points.size(); j++) {
                count[calSlope(points[i], points[j])]++;
            }
            if (count.size() == 1) {
                if (count[origin] > ans) ans = count[origin];
            }
            else {
                int overlap = count[origin];
                count.erase(origin);
                for (auto c : count) {
                    if (c.second + overlap > ans) ans = c.second + overlap;
                }
            }
        }
        return ans;
    }
private:
    std::pair<int, int> calSlope(const Point& p1, const Point& p2) {
        int x = p1.x - p2.x, y = p1.y - p2.y;
        if (x == 0 && y == 0) return {0, 0};
        else if (x == 0) return {0, 1};
        else if (y == 0) return {1, 0};
        else {
            bool sign = (x < 0 ^ y < 0);
            x = abs(x); y = abs(y);
            int g = gcd(x, y);
            if (sign) return {-x / g, y / g};
            else return {x / g, y / g};
        }
    }
    int gcd(int x, int y) {
        if (y == 0) return x;
        else return gcd(y, x % y);
    }
};

int main() {
    auto sol = std::make_unique<Solution>();
    std::vector<Point> points {Point(1,1), Point(2,2), Point(1,0), Point(2,1), Point(3,2)};
    assert(sol->maxPoints(points) == 3);
    points.clear();
    points.insert(points.begin(), {Point(0,0), Point(0,2), Point(0,-2), Point(0,3), Point(1,1)});
    assert(sol->maxPoints(points) == 4);
    points.clear();
    points.insert(points.begin(), {Point(0,0), Point(-1,1), Point(2,-2), Point(1,-1), Point(0,-1), Point(-1,1), Point(0,0)});
    assert(sol->maxPoints(points) == 6);
    points.clear();
    points.insert(points.begin(), {Point(0,0), Point(-1,-1), Point(2,2)});
    assert(sol->maxPoints(points) == 3);
    points.clear();
    assert(sol->maxPoints(points) == 0);
    points.emplace_back(2, 3);
    assert(sol->maxPoints(points) == 1);
    points.emplace_back(2, 3);
    assert(sol->maxPoints(points) == 2);
}

