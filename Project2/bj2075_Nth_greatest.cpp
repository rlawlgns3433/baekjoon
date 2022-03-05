//#include <iostream>
//#include <queue>
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	int N; cin >> N;
//	priority_queue<int, vector<int>, greater<int>> pq;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			int input; cin >> input;
//			pq.emplace(input);
//			if (pq.size() > N) {
//				pq.pop();
//			}
//		}
//	}
//	cout << pq.top();
//}