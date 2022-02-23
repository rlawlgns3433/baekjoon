//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//pair<short, short> list_set[10000000];
//
//bool compare(pair<int, int>& a, pair<int, int>& b) {
//	return a.first < b.first;
//}
//
//int main()
//{
//	cin.tie(0);
//	cin.sync_with_stdio(0);
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int input;
//		cin >> input;
//		if (list_set[input].first == NULL)
//		{
//			list_set[input].first = input;
//			++list_set[input].second;
//		}
//		else if (list_set[input].first != NULL) {
//			++list_set[input].second;
//		}
//	}
//	
//	sort(list_set, list_set + n);
//	for (auto& ele : list_set) {
//		for (int i = 0; i < ele.second; i++) {
//			cout << ele.first << '\n';
//		}
//	}
//}


//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
//	int n; cin >> n;
//	int num_set[10000] = { 0 };
//	for (int i = 0; i < n; i++) {
//		int input; cin >> input;
//		num_set[input]++;
//	}
//	for (int i = 0; i < 10001; i++) {
//		for (int j = 0; j < num_set[i]; j++) {
//			cout << i << '\n';
//		}
//	}
//}