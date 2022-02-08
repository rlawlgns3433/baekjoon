//#include <iostream>
//using namespace std;
//
//int main()
//{
//
//	int N, pre = 1, sav = 10;
//	cin >> N;
//	while (true) {
//		if (N <= sav) break;
//		if ((N / pre) % (sav / pre) >= 5)
//			N = (N / sav + 1) * sav;
//		else N = (N / sav) * sav;
//		pre = sav;
//		sav *= 10;
//	}
//	cout << N;
//}