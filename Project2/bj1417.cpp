//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//
//using namespace std;
//int main()
//{
//    int n = 0, count = 0;
//    cin >> n;
//    int* a = new int[n];
//    for (int i = 0; i < n; i++)
//        cin >> a[i];
//    for (int i = 1; i < n; i++){
//        while (a[0] <= a[i]) {
//            a[0] += 1;
//            a[i] -= 1;
//            count++;
//        }
//    }
//    cout << count << endl;
//}
//int main()
//{
//    int a1, a2, a3;
//    cin >> a1 >> a2 >> a3;
//    if (a1 == a2 && a2 == a3 && a3 == 60)
//        cout << "Equilateral" << endl;
//    else if ((a1 == a2 || a2 == a3 || a3 == a1) && (a1 + a2 + a3) == 180)
//        cout << "Isosceles" << endl;
//    else if (a1 != a2 && a2 != a3 && a1 != a3 && (a1 + a2 + a3) == 180)
//        cout << "Scalene" << endl;
//    else if ((a1 + a2 + a3) != 180)
//        cout << "Error" << endl;
//
//}