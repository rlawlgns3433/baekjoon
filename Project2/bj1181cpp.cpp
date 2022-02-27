#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compareword(string& a, string& b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

bool find(string s, vector<string> set) {
	for (int i = 0; i < set.size(); i++) {
		if (s == set[i]) {
			return 1;
		}
	}
	return 0;
}

int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	int N;
	cin >> N;
	vector<string> str_vec;
	for(int i = 0; i < N; i++){
		string temp_str; cin >> temp_str;
		if (find(temp_str, str_vec)) continue;
		else str_vec.emplace_back(temp_str);
	}
	sort(str_vec.begin(), str_vec.end(),compareword);
	for (auto& ele : str_vec) {
		cout << ele << '\n';
	}
}



//
//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//int count(int n) {
//    int count = 0;
//    for (int i = 1; i <= n; i++)
//        if (n % i == 0)
//            count++;
//    if (count % 2 != 0)
//        return n * (-1);
//    return n;
//}
//
//int solution(int left, int right) {
//    int answer = 0;
//    for (int i = left; i <= right; i++) {
//        if (count(i) % 2 == 0)
//            answer += count(i);
//        else {
//            answer -= count(i);
//        }
//    }
//    return answer;
//}
//int main()
//{
//
//
//    cout << solution(13, 17) << endl;
//}