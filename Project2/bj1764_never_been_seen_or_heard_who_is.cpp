//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_set>
//#include <algorithm>
//using namespace std;
//
//
//int main()
//{
//	cin.tie(0); cin.sync_with_stdio(0);
//
//	vector<string> never_heard, never_seen, never_heard_and_seen;
//
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n + m; i++) {
//		string name;
//		cin >> name;
//		if (i < n) never_heard.emplace_back(name);
//		else never_seen.emplace_back(name);
//	}
//
//	for (int i = 0; i < n; i++) {
//		string never_heard_name = never_heard[i]; 
//		for (int j = 0; j < m; j++) {
//			string never_seen_name = never_seen[j];
//			if (never_heard_name == never_seen_name)
//				never_heard_and_seen.emplace_back(never_heard_name);
//		}
//	}
//	sort(never_heard_and_seen.begin(), never_heard_and_seen.end());
//	int size = never_heard_and_seen.size();
//	cout << size << '\n';
//	for (const auto& name : never_heard_and_seen)
//		cout << name << '\n';
//}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cin.tie(0); cout.tie(0); cin.sync_with_stdio(0); cout.sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<string> n_heard, n_seen, n_heard_seen;
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> n_heard[i];
	}
	for (int i = 0; i < m; i++) {
		int temp; cin >> n_
	}
}