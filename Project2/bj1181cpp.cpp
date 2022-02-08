//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//bool CompareWord(string a, string b) {
//    if (a.length() == b.length()) {
//        return a < b;
//    }
//    else {
//        return a.length() < b.length();
//    }
//}
//
//int main() {
//    int N;
//    string str;
//    vector<string> word;
//    cin >> N;
//    for (int i = 0; i < N; i++) {
//        string temp;
//        cin >> temp;
//        word.push_back(temp);
//    }
//
//    sort(word.begin(), word.end(), CompareWord);
//
//    for (int i = 0; i < word.size(); i++) {
//        if (word[i] != word[i + 1]) {
//            cout << word[i] << "\n";
//        }
//    }
//    return 0;
//}
//
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