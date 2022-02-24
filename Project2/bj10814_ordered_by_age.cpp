//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//pair<int, string> list[100000];
//
//bool compare(const pair<int, string>& a, const pair<int, string>& b)
//{
//	return a.first < b.first;
//}
//
//void my10814()
//{
//	cin.tie(0); cin.sync_with_stdio(0);
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int age; string name;
//		cin >> age >> name;
//		list[i] = { age , name };
//	}
//	sort(list, list + n, compare);
//	for (int i = 0; i < n; i++) {
//		cout << list[i].first << " " << list[i].second << endl;
//	}
//}
//
//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//
//int main()
//{
//	multimap<int, string> m;
//	int n;  cin >> n;
//	for (int i = 0; i < n; i++) {
//		int age; string name;	
//		cin >> age >> name;
//		m.emplace(age, name);
//	}
//	for (pair<int, string> data : m) {
//		cout << data.first << " " << data.second << '\n';
//	}
//}