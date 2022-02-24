//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//bool compare(pair<int, int>& a, pair<int, int>& b) {
//    if (a.second == b.second)
//        return a.first < b.first;
//    return a.second < b.second;
//}
//
//int main() {
//    cin.tie(0); cin.sync_with_stdio(0);
//    int n; cin >> n;
//    pair<int, int> coord[100000];
//    for (int i = 0; i < n; i++) {
//        int x, y;
//        cin >> x >> y;
//        coord[i] = { x, y };
//    }
//    sort(coord, coord + n, compare);
//    for (int i = 0; i < n; i++) {
//        cout << coord[i].first << " " << coord[i].second << '\n';
//    }
//}