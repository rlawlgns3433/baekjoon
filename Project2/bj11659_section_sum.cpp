//#include <iostream>
//using namespace std;
//
//int list[100001];
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	int N, M;
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++)
//	{
//		int input;
//		cin >> input;
//		list[i] = input + list[i - 1];
//	}
//	while (M--) {
//		int a, b;
//		cin >> a >> b;
//		cout << list[b] - list[a - 1] << '\n';
//	}
//}