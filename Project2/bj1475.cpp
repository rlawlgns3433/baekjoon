#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int cnt[10] = { 0 };
int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) 
		cnt[int(str[i] - '0')]++;
	int max = 1;
	for (int i = 0; i <= 9; i++) {
		if (i == 6 || i == 9) {
			if (max < ceil((double(cnt[6]) + double(cnt[9]) / double(2)))) max = ceil((double(cnt[6]) + double(cnt[9]) / double(2)));
		}
		else if (cnt[i] > max) max = cnt[i];
	}
	cout << max;
}