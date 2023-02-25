#include <iostream>
#include <vector>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	vector<int> v;
	v.assign(6, 0);
	short a, b, c;
	cin >> n;

	cin >> v[0] >> v[1] >> v[2];
	v[3] = v[0], v[4] = v[1], v[5] = v[2];
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b >> c;
		int tmp1 = v[0];
		int tmp2 = v[1];
		int tmp3 = v[2];
		int tmp4 = v[3];
		int tmp5 = v[4];
		int tmp6 = v[5];

		v[0] = max(tmp1 + a, tmp2 + a);
		v[1] = max(tmp1 + b, max(tmp2 + b, tmp3 + b));
		v[2] = max(tmp2 + c, tmp3 + c);
		v[3] = min(tmp4, tmp5) + a;
		v[4] = min(tmp4, min(tmp5, tmp6)) + b;
		v[5] = min(tmp5, tmp6) + c;
	}

	cout << max(v[0], max(v[1], v[2])) << ' ' << min(v[3], min(v[4], v[5]));
}