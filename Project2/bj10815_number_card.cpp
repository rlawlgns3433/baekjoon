//#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//using namespace std;
//
//bool binary_search(int N, vector<int>& s) {
//    auto left = s.begin();
//    auto right = s.end();
//    while (true) {
//        auto range_legnth = distance(left, right);
//        auto mid_index = floor(range_legnth / 2);
//        auto mid_element = *(left + mid_index);
//
//        if (mid_element == N) return true;
//        else if (mid_element > N)
//            advance(right, -mid_index);
//        else advance(left, mid_index);
//
//        if (range_legnth == 1) return false;
//    }
//}
//
//int main()
//{
//    int N, M;
//    cin >> N;
//    vector<int> setA;
//    for (int i = 0; i < N; i++) {
//        int tempinput; cin >> tempinput;
//        setA.emplace_back(tempinput);
//    }
//    sort(setA.begin(), setA.end());
//    setA.shrink_to_fit();
//    cin >> M;
//    vector<int> setB;
//    for (int i = 0; i < M; i++) {
//        int tempinput; cin >> tempinput;
//        setB.emplace_back(tempinput);
//    }
//    setB.shrink_to_fit();
//    for (int i = 0; i < M; i++) {
//        if (binary_search(setB[i], setA)) cout << 1 << ' ';
//        else cout << 0 << ' ';
//    }
//    
//}

