#include <iostream>
#include <vector>
#include <algorithm>
#define space ' '
using namespace std;

class Point
{
private:
	int index;
	int value;
	int rank;
public:
	Point(int i, int v) : index(i), value(v) {}
	void SetRank(int r) { rank = r; }
	int GetRank() { return rank; }
	int GetValue() { return value; }
	int GetIndex() { return index; }

	bool operator < (const Point& other)
	{
		return value < other.value;
	}
};

bool Compare(Point& lhs, Point& rhs)
{
	return lhs.GetIndex() < rhs.GetIndex();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<Point> points;
	int value = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> value;
		Point p = Point(i, value);
		points.push_back(p);
	}

	sort(points.begin(), points.end());

	int r = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i > 0 && points[i].GetValue() == points[i - 1].GetValue())
		{

			points[i].SetRank(--r);
		}
		else
		{
			points[i].SetRank(r);
		}
		r++;
	}

	sort(points.begin(), points.end(), Compare);

	for (int i = 0; i < n; ++i)
	{
		cout << points[i].GetRank() << space;
	}
}