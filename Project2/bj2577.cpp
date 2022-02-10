//#include <iostream>
//using namespace std;
//
//int main() {
//    int A, B, C, product, a[10] = { 0 };
//    cin >> A >> B >> C;
//    product = A * B * C;
//    while (1) {
//        switch (product % 10) {
//        case 0: a[0]++; break;
//        case 1: a[1]++; break;
//        case 2: a[2]++; break;
//        case 3: a[3]++; break;
//        case 4: a[4]++; break;
//        case 5: a[5]++; break;
//        case 6: a[6]++; break;
//        case 7: a[7]++; break;
//        case 8: a[8]++; break;
//        case 9: a[9]++; break;
//        }
//        product /= 10;
//        if (product == 0)
//            break;
//    }
//    for (int i = 0; i < 10; i++)
//        cout << a[i] << endl;
//}