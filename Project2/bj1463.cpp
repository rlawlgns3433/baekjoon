//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    int num;
//    cin >> num;
//    int* cnt = new int[num+1]();
//    for (int i = 2; i <= num; i++) {
//        cnt[i] = cnt[i - 1] + 1;
//        if (i % 3 == 0)
//            cnt[i] = min(cnt[i / 3] + 1, cnt[i]);
//        if (i % 2 == 0)
//            cnt[i] = min(cnt[i / 2] + 1, cnt[i]);
//    }
//    cout << cnt[num];
//}