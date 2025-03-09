#include <iostream>
using namespace std;

void Solution(int x, int y)
{
	int distance = y - x;
	int center = static_cast<int>(sqrt(distance));
	int length = center * 2 - 1;
	int remain = distance - center * center;

	if (remain != 0)
	{
		if (remain <= center)
			length += 1;
		else
			length += 2;
	}

	cout << length << '\n';
}

int main()
{
	int n;
	cin >> n;

	int x, y;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		Solution(x, y);
	}
}