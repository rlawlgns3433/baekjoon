//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cin.tie(0); cin.sync_with_stdio(0);
//	int N, K;
//	cin >> N >> K;
//	int* c = new int[N];
//	for (int i = 1; i <= N; i++) {
//		cin >> c[N-i];
//	}
//
//	int i = 0, count = 0;
//	while (K != 0) {
//		if (K / c[i]) {
//			count += K / c[i];
//			K = K % c[i];
//		}
//		else i++;
//	}
//	cout << count;
//}