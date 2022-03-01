//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//bool compareword(string& a, string& b) {
//	if (a.length() == b.length()) {
//		return a < b;
//	}
//	return a.length() < b.length();
//}
//
//
//int main()
//{
//	cin.tie(0); cin.sync_with_stdio(0);
//	int N;
//	cin >> N;
//	vector<string> str_vec;
//	for(int i = 0; i < N; i++){
//		string temp_str; cin >> temp_str;
//		if (find(str_vec.begin(), str_vec.end(), temp_str) == str_vec.end()) str_vec.emplace_back(temp_str);
//	}
//	sort(str_vec.begin(), str_vec.end(),compareword);
//	for (auto& ele : str_vec) {
//		cout << ele << '\n';
//	}
//}