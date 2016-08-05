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
	Point operator + (const Point &p) {
		return Point(x + p.x, y + p.y);
	}
	Point operator - (const Point &p) {
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
	double dot(const Point &p) {
		return x * p.x + y * p.y;
	}
	double cross(const Point &p) {
		return x * p.y - y * p.x;
	}
	// p. 375
	bool isOrthogonal(const Point &p) {	// 直交判定。
		return equals(dot(p), 0);
	}
	bool isParallel(const Point &p) {	// 平行判定。
		return equals(cross(p), 0);
	}
	// p. 381
	double getDistance(Point p) {
		return (*this - p).abs();
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
	Point reflect(Point &a) {
		Point tmp;
		tmp = project(a);
		tmp = tmp - a;
		tmp = tmp * 2;
		tmp = a + tmp;
		return tmp;
	}
};

// p. 368
typedef Segment Line;	// 直線を表す。

double getDistanceLP(Line l, Point p)
{
	// Point left = l.p2 - l.p1;
	// Point right = p - l.p1;
	// double cross = left.cross(right);
	// Point right1 = l.p2 - l.p1;
	// double abs0 = right1.abs();
	// Point right2 = cross / abs0;
	// double abs1 = right2.abs();
	// return abs1;
	double tmp = fabs((l.p2 - l.p1).cross(p - l.p1)) / (l.p2 - l.p1).abs();
	// printf("%f\n", tmp);
	return tmp;
}

double getDistanceSP(Segment s, Point p) {
	if ((s.p2 - s.p1).dot(p - s.p1) < 0) {
		return (p - s.p1).abs();
	}
	if ((s.p1 - s.p2).dot(p - s.p2) < 0) {
		return (p - s.p2).abs();
	}
	return getDistanceLP(s, p);
}
// p. 386
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
int ccw(Point p0, Point p1, Point p2)
{
	Vector a = p1 - p0;
	Vector b = p2 - p0;
	if (a.cross(b) > EPS) return COUNTER_CLOCKWISE;
	if (a.cross(b) < -EPS) return CLOCKWISE;
	if (a.dot(b) < -EPS) return ONLINE_BACK;
	if (a.norm() < b.norm()) return ONLINE_FRONT;
	return ON_SEGMENT;
}
// p. 389
bool intersect(Point p1, Point p2, Point p3, Point p4)
{
	int ccw0 = ccw(p1, p2, p3);
	int ccw1 = ccw(p1, p2, p4);
	int ccw2 = ccw(p3, p4, p1);
	int ccw3 = ccw(p3, p4, p2);
	// printf("%d, %d, %d, %d\n", ccw0, ccw1, ccw2, ccw3);
	return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
		ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
bool intersect(Segment s1, Segment s2)
{
	return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}
// p. 383
double getDistance(Segment s1, Segment s2) {
	if (intersect(s1, s2)) {
		return 0;
	}
	return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
		   min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

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

void solve_378(void)	// Accepted.
{
	int xp1, yp1, xp2, yp2;
	scanf("%d%d%d%d", &xp1, &yp1, &xp2, &yp2);
	int q;
	scanf("%d", &q);
	Segment segment = Segment(Point(xp1, yp1), Point(xp2, yp2));
	for (int i = 0; i < q; i++) {
		int xp, yp;
		scanf("%d%d", &xp, &yp);
		Point tmp_point = Point(xp, yp);
		Point result = segment.reflect(tmp_point);
		printf("%.10f %.10f\n", result.x, result.y);
	}
}

void solve_380(void)	// Accepted.
{
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int x0, y0, x1, y1, x2, y2, x3, y3;
		scanf("%d%d%d%d%d%d%d%d", &x0, &y0, &x1, &y1, &x2, &y2, &x3, &y3);
		Segment segment_0 = Segment(Point(x0, y0), Point(x1, y1));
		Segment segment_1 = Segment(Point(x2, y2), Point(x3, y3));
		double answer = getDistance(segment_0, segment_1);
		printf("%.10f\n", answer);
	}
}

int main(void)
{
	// solve_374();
	// solve_376();
	// solve_378();
	solve_380();
	return 0;
}
