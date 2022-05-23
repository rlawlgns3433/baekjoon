#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int caseSize;
	cin >> caseSize;
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++)
	{
		int w, h, n;
		cin >> h >> w >> n;

		int floor = n % h, room_num = 0;

		if (floor == 0)
		{
			floor = h;
		}
		room_num = ceil((float)n / h);
		cout << floor * 100 + room_num << '\n';
	}
}