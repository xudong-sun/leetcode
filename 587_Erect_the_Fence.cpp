/*
There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.
*/


#include "essentials.h"

struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

std::ostream& operator<<(std::ostream& os, Point point) {
  os << '<' << point.x << ", " << point.y << '>';
  return os;
}

// use two "monotonic queue"s, one for the left boundary, one for the right boundary
class Solution {
public:
  std::vector<Point> outerTrees(std::vector<Point>& points) {
    auto pointCmp = [](Point p1, Point p2) { return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y); };
    auto pointEq = [](Point p1, Point p2) { return p1.x == p2.x && p1.y == p2.y; };
    auto pointHash = [](Point p) { return p.x * 100 + p.y; };
    std::unordered_set<Point, decltype(pointHash), decltype(pointEq)> result(10, pointHash, pointEq);
    std::sort(points.begin(), points.end(), pointCmp);
    // check if all points on a horizontal line
    if (points[0].x == points[points.size()-1].x) return points;
    // set up two queues
    std::deque<Point> left, right;
    size_t i = 0, j = 0;
    while (i < points.size()) {
      int x = points[i].x;
      while (j < points.size() && points[j].x == x) j++;
      j--;  // so now, for any i<k<j, points[k].x == x
      // if this is the first row or the last row, add all points to boundary
      if (i == 0 || j == points.size()-1) {
        for (size_t k = i; k <= j; k++) result.insert(points[k]);
      }
      // check the left boundary
      int y = points[i].y;
      while (left.size() > 1) {
        size_t last = left.size() - 1;
        int x1 = left[last-1].x, y1 = left[last-1].y;
        int x2 = left[last].x, y2 = left[last].y;
        if (double(y2-y1)/(x2-x1)*(x-x2)+y2 > y+EPS) left.pop_back();
        else break;
      }
      left.push_back(points[i]);
      // check the right boundary
      y = points[j].y;
      while (right.size() > 1) {
        size_t last = right.size() - 1;
        int x1 = right[last-1].x, y1 = right[last-1].y;
        int x2 = right[last].x, y2 = right[last].y;
        if (double(y2-y1)/(x2-x1)*(x-x2)+y2 < y-EPS) right.pop_back();
        else break;
      }
      right.push_back(points[j]);
      i = j + 1, j = i;
    }
    // collect the boundary points
    result.insert(left.cbegin(), left.cend());
    result.insert(right.cbegin(), right.cend());
    return std::vector<Point>(result.cbegin(), result.cend());
  }
private:
  constexpr static double EPS = 1e-4;
};

int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<Point> points{Point(1,1), Point(2,2), Point(2,0), Point(2,4), Point(3,3), Point(4,2)};
  std::cout << sol->outerTrees(points) << std::endl; 
  points.clear();
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      points.push_back(Point(i,j));
  std::cout << sol->outerTrees(points) << std::endl;
  points = std::vector<Point> {Point(1,2), Point(2,2), Point(4,2)};
  std::cout << sol->outerTrees(points) << std::endl;
  points = std::vector<Point> {Point(2,1), Point(2,2), Point(2,4)};
  std::cout << sol->outerTrees(points) << std::endl;
  points = std::vector<Point> {Point(1,1)};
  std::cout << sol->outerTrees(points) << std::endl;
}



