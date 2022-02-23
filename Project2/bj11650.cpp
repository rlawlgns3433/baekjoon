//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//void mySort()
//{
//    cin.tie(0); cin.sync_with_stdio(0);
//    vector<pair<int, int>> dot;
//    int n; cin >> n;
//    for (int i = 0; i < n; i++) {
//        int x, y;
//        cin >> x >> y;
//        dot.push_back({ x, y });
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (dot[i].first > dot[j].first) {
//                swap(dot[i], dot[j]);
//            }
//            if (dot[i].first == dot[j].first && dot[i].second > dot[j].second)
//                swap(dot[i], dot[j]);
//        }
//    }
//    for (int i = 0; i < n; i++)
//        cout << dot[i].first << " " << dot[i].second << '\n';
//
//}
//
///////////////////////////////////////////////////////////////////////////////////////////////////
//
//bool compare(const pair<int, int>& a, const pair<int, int>& b) {
//    if (a.first == b.first)
//        return a.second < b.second;
//    return a.first < b.first;
//}
//
//void sort2() {
//    pair<int, int> p[200000];
//    int n; cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> p[i].first >> p[i].second;
//    }
//    sort(p, p + n, compare);
//    for (int i = 0; i < n; i++)
//        cout << p[i].first << " " << p[i].second << '\n';
//}
//
//
//class Coord {
//public:
//	int x;
//	int y;
//
//	bool operator <(Coord xy) {
//		if (this->x == xy.x)
//			return this->y < xy.y;
//		return this->x < xy.x;
//	}
//};
//
//int main() {
//	//int N;
//	//cin >> N;
//	//Coord* coords = new Coord[N];
//	//for (int i = 0; i < N; i++) {
//	//	cin >> coords[i].x >> coords[i].y;
//	//}
//	//sort(coords, coords + N);
//
//	//for (int i = 0; i < N; i++) {
//	//	cout << coords[i].x << " " << coords[i].y << "\n";
//	//}
//
//    sort2();
//    //mySort();
//}