//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <algorithm>
//#include <stdio.h>
//#include <stdlib.h>
//#define SWAP(a,b,t) ((t) = (a), (a) = (b), (b) = (t))
//
//int recursive(int n) {
//	int temp=0;
//	while (n != 0) {
//		temp = temp + n % 10;
//		n /= 10;
//	}
//	return temp;
//}
//
//void tobinary(int n) {
//	if (n / 2 == 0) printf("%d",n);
//	else {
//		tobinary(n / 2);
//		printf("%d", n % 2);
//	}
//}
//
//int compare(const void* x, const void* y) {
//	return (*(int*)x - *(int*)y);
//}
//
//int main()
//{
//	int num,a;
//	scanf("%d", &num);
//	printf("%d\n\n",recursive(num));
//	scanf("%d", &a);
//	tobinary(a);
//}
//
//
//
//int main()
//{
//	int N;
//	scanf("%d", &N);
//	int *a = (int*)malloc(sizeof(int)*N);
//	for (int i = 0; i < N; i++) {
//		scanf("%d", &a[i]);
//	}
//	qsort(a, N, sizeof(int),compare);
//	for (int i = 0; i < N; i++)
//		printf("%d\n", a[i]);
//}
