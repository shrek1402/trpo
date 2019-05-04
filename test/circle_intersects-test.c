#include "geometry.h"

int circle_intersects(double x, double y, double r, double x1, double y1,
                      double r1) {
  int flag;
  double N;
  N = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
  if (x == x1 && y == y1 && r == r1) {
    flag = 1;
  } else if (x == x1 && y == y1 && (r < r1 || r > r1)) {
    flag = 0;
  } else if (N == (r + r1)) {
    flag = 1;
  } else if (N <= (r + r1)) {
    flag = 1;
  } else
    flag = 0;
  return flag;
}
TEST_CASE("CIRCLEINTERSECTS", "[int]") {
  REQUIRE(circle_intersects(0, 0, 2, 3, 0, 2) == 1);
  REQUIRE(circle_intersects(-5, -6, 2, 0, 0, 2) == 0);
  REQUIRE(circle_intersects(-5, -6, 2, 5, 7, 2) == 0);
  REQUIRE(circle_intersects(0, 0, 2, 0, 0, 2) == 1);
  REQUIRE(circle_intersects(0, 0, 2, 4, 0, 2) == 1);
  cout << "Test sircle intersects" << endl;
}
