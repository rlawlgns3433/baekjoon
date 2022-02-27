//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//
//int main()
//{
//    int M, N;
//    vector<int> list;
//    cin >> M >> N;
//    for (int i = M; i <= N; i++) {
//        int rt = sqrt(i);
//        if (rt == 1 && i != 1) {
//            list.emplace_back(i);
//            continue;
//        }
//        if (i % 2) {
//            for (int j = 2; j <= rt; j++) {
//                if (i % j == 0) break;
//                if (j == rt)
//                    list.emplace_back(i);
//            }
//        }
//    }
//    if (list.size() == 0) {
//        cout << -1;
//        return 0;
//    }
//
//    sort(list.begin(), list.end());
//    int result = 0;
//    for (auto i : list)
//        result += i;
//    cout << result << '\n' << list[0];
//}