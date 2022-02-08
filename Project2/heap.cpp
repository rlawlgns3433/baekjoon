//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_ELEMENT 100
//
//typedef struct heapType {
//	int heap[MAX_ELEMENT];
//	int heap_size;
//}heapType;
//
//heapType* createHeap() {
//	heapType* heap = (heapType*)malloc(sizeof(heapType));
//	heap->heap_size = 0;
//	return heap;
//}
//
//void insertHeap(heapType* h, int item) {
//	int i;
//	h->heap_size += 1;
//	i = h->heap_size;
//	while ((i != 1) && item > h->heap[i / 2]) {
//		h->heap[i] = h->heap[i / 2];
//		i /= 2;
//	}
//	h->heap[i] = item;
//}
//
//int deleteHeap(heapType* h) {
//	int parent, child;
//	int item, temp;
//	item = h->heap[1];
//	temp = h->heap[h->heap_size];
//	h->heap_size -= 1;
//	parent = 1;
//	child = 2;
//	while (child <= h->heap_size) {
//		if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1]))
//			child++;
//		if (temp >= h->heap[child]) break;
//		else {
//			h->heap[parent] = h->heap[child];
//			parent = child;
//			child *= 2;
//		}
//	}
//	h->heap[parent] = temp;
//	return item;
//}
//
//void printHeap(heapType* h) {
//	int i;
//	printf("heap : ");
//	for (i = 1; i <= h->heap_size; i++){
//		printf("%d", h->heap[i]);
//		if (i != h->heap_size) printf(", ");
//	}
//}
//
//int main()
//{
//
//	heapType* h = createHeap();
//	insertHeap(h, 1);
//	insertHeap(h, 2);
//	insertHeap(h, 3);
//	insertHeap(h, 4);
//	insertHeap(h, 6);
//	insertHeap(h, 5);
//	insertHeap(h, 8);
//	insertHeap(h, 14);
//	printHeap(h);
//}