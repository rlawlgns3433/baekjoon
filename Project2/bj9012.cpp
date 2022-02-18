//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//string testpair(string str) {
//	stack<string> s;
//	for (int i = 0; i < str.length(); i++) {
//		if (str[i] == '(') s.push("(");
//		else if (str[i] == ')') {
//			if (s.empty()) { return "NO"; break; }
//			else s.pop();
//		}
//	}
//	if (s.empty()) return "YES";
//	else return "NO";
//}
//
//int main()
//{
//	int n;
//	string str;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> str;
//		cout << testpair(str) << '\n';
//	}
//}