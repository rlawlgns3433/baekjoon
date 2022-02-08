//#include <iostream>
//using namespace std;
//
//
//int main() {
//    int n, rear, front = 0;
//    cin >> n;
//    int* a = (int*)malloc(sizeof(int) *1000);
//    for (int i = 0; i < n; i++) {
//        a[i] = i + 1;
//    }
//    rear = n - 1;
//    while (front != rear) {
//        if (front % 2 == 0){
//            cout << a[front++] << " ";
//        }
//        else a[++rear] = a[front++];
//    }
//    cout << a[front];
//}