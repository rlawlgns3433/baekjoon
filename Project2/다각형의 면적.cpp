#include <iostream>
#include <vector>
using namespace std;

class Point
{
public:
	Point(long long _x, long long _y) : x(_x), y(_y) {}
	long long x, y;
};

int main()
{
	int n;
	cin >> n;

	vector<Point*> points;
	long long x, y;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		Point* point = new Point(x, y);
		points.push_back(point);
	}
	points.push_back(points.front());

	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += (points[i]->x * points[i + 1]->y) - (points[i + 1]->x * points[i]->y);
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(sum / 2.0);
}