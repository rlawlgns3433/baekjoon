//#include <iostream>
//#include <cmath>
//using namespace std;
//
////int evalcount(int x, int y){
////	int count = 0,dist = y - x, max_move = pow(dist,0.5), square = pow(max_move, 2);
////
////	if (dist == square)
////		count = max_move * 2 - 1;
////	else if (dist <= square + max_move)
////		count = max_move * 2;
////	else if (dist > square + max_move)
////		count = max_move * 2 + 1;
////	else if(dist < 4)
////		count = dist;
////	return count;
////}
////
////int main()
////{
////	cin.tie(0); cin.sync_with_stdio(0);
////	int T; cin >> T;
////	for (int i = 0; i < T; i++) {
////		int x, y;
////		cin >> x >> y;
////		cout << evalcount(x, y) << '\n';
////	}
////}
//
//int main()
//{
//	int T; long long x, y, dis, k, s;
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	cin >> T;
//	for (int i = 0; i < T; i++) {
//		cin >> x >> y;
//		dis = y - x;
//		int j = sqrt(dis);
//		while (1) {
//			s = j * (j + 1);
//			if (dis == s - j) {
//				k = j;
//				cout << 2 * k - 1 << '\n';
//				break;
//			}
//			else if (dis <= s) {
//				k = j;
//				cout << 2 * k << '\n';
//				break;
//			}
//			else if (dis < s + j + 1) {
//				k = j;
//				cout << 2 * k + 1 << '\n';
//				break;
//			}
//			j++;
//		}
//	}
//}