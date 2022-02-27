//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <deque>
//#include <queue>
//using namespace std;
//
//int main(){
//
//	cin.tie(0); cin.sync_with_stdio(0);
//	deque<int> q;
//	vector<int> v;
//	int Test; cin >> Test;
//	int command_count; cin >> command_count;
//	for(int t = 0; t < Test; t++){
//		for (int i = 0; i < command_count; i++) {
//			char type; cin >> type;
//			if (type == 'I') 
//			{
//				int num; cin >> num;
//				q.emplace_back(num);
//				sort(q.front(), q.back());
//			}
//			else if (type == 'D')
//			{
//				int num; cin >> num;
//				if (num == 1) {
//					q.pop_back();
//				}
//				else q.pop_front();
//			}
//		}
//		if (!q.empty()) {
//			cout << q.front() << ' ' << q.back() << '\n';
//		}
//		else cout << "EMPTY" << '\n';
//	}
//
//
//	return  0;
//}