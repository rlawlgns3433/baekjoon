// 가장 가까운 두 점
// boj2261번 Divide and Conquer

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n;
double answer = 2e+8;

struct Point
{
	int x, y;
};

bool compare(Point p1, Point p2)
{
	return p1.x < p2.x;
}

double divide(Point* p, int left_x, int right_x)
{
	int midOfIndex = (left_x + right_x) / 2;
	int midOfXValue = p[midOfIndex].x;

	if (p[left_x].x == p[left_x + 1].x && p[left_x].y == p[left_x + 1].y) return 0;
	if (right_x - left_x == 1)
	{
		return sqrt(pow(p[0].x - p[1].x, 2) + pow(p[0].y - p[1].y, 2));
	}
	else if (right_x - left_x == 2)
	{
		double temp = sqrt(pow(p[0].x - p[1].x, 2) + pow(p[0].y - p[1].y, 2));
		answer = min(temp, sqrt(pow(p[0].x - p[2].x, 2) + pow(p[0].y - p[2].y, 2)));
		answer = min(answer, sqrt(pow(p[2].x - p[1].x, 2) + pow(p[2].y - p[1].y, 2)));
		return answer;
	}
	else
	{
		double left_min = divide(p, left_x, midOfIndex);
		double right_min = divide(p, midOfIndex + 1, right_x);
		answer = min(left_min, right_min);
	}
	return pow(answer, 2);
}

int main()
{
	cin >> n;

	Point* p = new Point[n];

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		p[i].x = x; p[i].y = y;
	}

	sort(p, p + n - 1, compare);
	cout << divide(p, 0, n - 1);

}