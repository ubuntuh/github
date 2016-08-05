#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

// p. 371
#define EPS (1e-10)	// Epsilon.
#define equals(a, b) (fabs((a) - (b)) < EPS)

// p. 367
class Point {	// 点を表す。
public:
	double x;
	double y;
	Point(double x = 0, double y = 0): x(x), y(y) {}
	Point operator + (Point &p) {
		return Point(x + p.x, y + p.y);
	}
	Point operator - (Point &p) {
		return Point(x - p.x, y - p.y);
	}
	Point operator * (double a) {
		return Point(x * a, y * a);
	}
	Point operator / (double a) {
		return Point(x / a, y / a);
	}
	bool operator < (const Point &p) const {
		return x != p.x ? x < p.x : y < p.y;
	}
	bool operator == (const Point &p) const {
		return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
	}
	double norm() {
		return x * x + y * y;
	}
	double abs() {
		return sqrt(norm());
	}
	void print() {
		printf("(%.3f, %.3f)\n", x, y);
	}
	// p. 372
	double dot(Point &p) {
		return x * p.x + y * p.y;
	}
	double cross(Point &p) {
		return x * p.y - y * p.x;
	}
	// p. 375
	bool isOrthogonal(Point &p) {	// 直交判定。
		return equals(dot(p), 0);
	}
	bool isParallel(Point &p) {	// 平行判定。
		return equals(cross(p), 0);
	}
};
Point operator * (double a, Point &p) {
	return p * a;
}

typedef Point Vector;	// ベクトルを表す。

class Segment {	// 線分を表す。
public:
	Point p1;
	Point p2;
	Segment(Point p1 = Point(), Point p2 = Point()): p1(p1), p2(p2) {}
	bool isOrthogonal(Segment &a) {
		Point left = p2 - p1;
		Point right = a.p2 - a.p1;
		return equals(left.dot(right), 0);
	}
	bool isParallel(Segment &a) {
		Point left = p2 - p1;
		Point right = a.p2 - a.p1;
		return equals(left.cross(right), 0);
	}
	void print() {
		printf("(%.3f, %.3f), (%.3f, %.3f)\n", p1.x, p1.y, p2.x, p2.y);
	}
	Point project(Point &a) {
		Point base = p2 - p1;
		Point left = a - p1;
		double r = left.dot(base) / base.norm();
		Point tmp = base * r;
		return p1 + tmp;
	}
};

// p. 368
typedef Segment Line;	// 直線を表す。

class Circle {	// 円を表す。
public:
	Point c;
	double r;
	Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};

typedef vector<Point> Polygon;	// 多角形を表す。

void solve_374(void)	// Accepted.
{
	int q;
	scanf("%d", &q);
	// printf("q = %d\n", q);
	for (int i = 0; i < q; i++) {
		int x0, y0, x1, y1, x2, y2, x3, y3;
		scanf("%d%d%d%d%d%d%d%d", &x0, &y0, &x1, &y1, &x2, &y2, &x3, &y3);
		// printf("(%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", x0, y0, x1, y1, x2, y2, x3, y3);
		Segment segment_0 = Segment(Point(x0, y0), Point(x1, y1));
		Segment segment_1 = Segment(Point(x2, y2), Point(x3, y3));
		int answer = -1;
		if (segment_0.isParallel(segment_1)) {
			answer = 2;
		} else if (segment_0.isOrthogonal(segment_1)) {
			answer = 1;
		} else {
			answer = 0;
		}
		printf("%d\n", answer);
	}
}

void solve_376(void)	// Accepted.
{
	int xp1, yp1, xp2, yp2;
	scanf("%d%d%d%d", &xp1, &yp1, &xp2, &yp2);
	int q;
	scanf("%d", &q);
	// printf("q = %d\n", q);
	Segment segment = Segment(Point(xp1, yp1), Point(xp2, yp2));
	for (int i = 0; i < q; i++) {
		int xp, yp;
		scanf("%d%d", &xp, &yp);
		Point tmp_point = Point(xp, yp);
		Point result = segment.project(tmp_point);
		printf("%.10f %.10f\n", result.x, result.y);
	}
}

int main(void)
{
	// solve_374();
	solve_376();
	return 0;
}
