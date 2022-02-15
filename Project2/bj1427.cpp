//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    int N, a[12];
//    cin >> N;
//    int size = 0, copy_N = N;
//    while(1){
//        if (N > 0) {
//            size++;
//            N /= 10;
//        }
//        else break;
//    }
//    for (int i = 0; i < size; i++) {
//        if (copy_N > 0) {
//            a[i] = copy_N % 10;
//            copy_N /= 10;
//        }
//    }
//    sort(a, a + size);
//    for (int i = size-1; i >= 0; i--)
//        cout << a[i];
//}