//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//int N, ans = 0;vector<int> list;
//void long_bj11179() {
//	cin >> N;
//	while (N != 0) {
//		list.push_back(N % 2);
//		N /= 2;
//	}
//	int idx = 0;
//	while (!list.empty()) {
//		ans += (list.back() * pow(2, idx));
//		list.pop_back();
//		idx++;
//	}
//	cout << ans;
//}
//
//int main()
//{
//	int N, ans = 0;
//	cin >> N;
//	while (N > 0) {
//		ans <<= 1;
//		if (N & 1) ans++;
//		N >>= 1;
//	}
//	cout << ans;
//
//	long_bj11179();
//}