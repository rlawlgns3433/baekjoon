//#include <iostream>
//
//long long  fibonacci(long long n) {
//    if (n <= 1) return n;
//    long long a = 0, b = 1, temp = 0;
//    for (long long i = 0; i < n-1; i++) {
//        temp = a;
//        a = b;
//        b = temp + b;
//    }
//    return b;
//}
//
//int main() {
//    std::cin.tie(0); std::cin.sync_with_stdio(0);
//    long long n;
//    std::cin >> n;
//    std::cout << fibonacci(n);
//}