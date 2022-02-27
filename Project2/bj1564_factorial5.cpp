//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cin.tie(0); cin.sync_with_stdio(0);
//	int N;
//	long long result = 1;
//	cin >> N;
//	for (int i = 2; i <= N; i++) {
//		result *= i;
//		while (result % 10 == 0){
//			result /= 10;
//		}
//		result %= 10000000000000000000;
//	}
//	result %= 100000;
//	if (result >= 10000)
//		printf("%lld", result);
//	else if (result >= 1000)
//		printf("0%lld", result);
//	else if (result >= 100)
//		printf("00%ld", result);
//	else if (result >= 10)
//		printf("%000ld", result);
//	else printf("0000%lld", result);
//
//}
