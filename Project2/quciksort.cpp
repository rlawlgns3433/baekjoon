//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>	
//#include <stdlib.h>	
//
//typedef int element;
//void quicksort(element a[], int left, int right) {
//	int i, j, pivot;
//	element temp;
//	if (left < right) {
//		i = left;
//		j = right + 1;
//		pivot = a[left];
//		do {
//			do i++; while (a[i] < pivot);
//			do j--; while (a[j] > pivot);
//			if (i < j) {
//				temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		} while (i < j);
//		temp = a[left];
//		a[left] = a[j];
//		a[j] = temp;
//		quicksort(a, left, j - 1);
//		quicksort(a, j + 1, right);
//	}
//}
//
//int main()
//{
//	element a[] = { 89,15,61,21,58,63 };
//	quicksort(a, 0, 5);
//	for (int i = 0; i < 6; i++) {
//		printf("%d ", a[i]);
//	}
//}