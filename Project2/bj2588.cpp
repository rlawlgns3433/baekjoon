//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//int main()
//{
//    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    vector<int> v;
//    int n1, n2, temp;
//    cin >> n1 >> n2;
//    temp = n1 * n2;
//    for (int i = 0; i < 3; i++) {
//        if (n2 > 10) {
//            v.emplace_back((n2 % 10) * n1);
//            n2 /= 10;
//        }
//        else v.emplace_back(n2 * n1);
//    }
//    for (const auto& ele : v)
//        cout << ele << '\n';
//    cout << temp << endl;
//}