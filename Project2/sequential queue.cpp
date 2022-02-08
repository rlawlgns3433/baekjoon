//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX_SIZE 100
//
//typedef int element;
//typedef struct queueType {
//	element queue[MAX_SIZE];
//	int front, rear;
//};
//
//queueType* createQueue() {
//	queueType* Q = (queueType*)malloc(sizeof(queueType));
//	Q->front = -1;
//	Q->rear = -1;
//	return Q;
//}
//
//int isEmpty(queueType* Q) {
//	if (Q->front == Q->rear)
//		return 1;
//	else return 0;
//}
//
//int isFull(queueType* Q) {
//	if (Q->rear == MAX_SIZE - 1)
//		return 1;
//	else return 0;
//}
//
//void enQueue(queueType* Q, element item) {
//	if (isFull(Q)) fprintf(stderr, "queue is full\n");
//	else {
//		Q->rear = Q->rear + 1;
//		Q->queue[Q->rear] = item;
//	}
//}
//
//element deQueue(queueType* Q) {
//	element item;
//	if (isEmpty(Q)) {
//		fprintf(stderr, "queue is empty\n");
//		exit(1);
//	}
//	else {
//		Q->front += 1;
//		return Q->queue[Q->front];
//	}
//}
//
//element peek(queueType* Q) {
//	if (isEmpty(Q)) {
//		fprintf(stderr, "queue is empty\n");
//		exit(1);
//	}
//	else {
//		return Q->queue[Q->front + 1];
//	}
//}
//
//void printQueue(queueType* Q) {
//	int i;
//	for (i = Q->front + 1; i <= Q->rear; i++) {
//		printf("%d ", Q->queue[i]);
//	}
//}
//
//int main()
//{
//	queueType* Q = createQueue();
//	element item;
//	printQueue(Q); getchar();
//	enQueue(Q, 1); printQueue(Q); getchar();
//	enQueue(Q, 2); printQueue(Q); getchar();
//	enQueue(Q, 3); printQueue(Q); getchar();
//	enQueue(Q, 4); printQueue(Q); getchar();
//	item = peek(Q);
//	printf("peek : %d\n", item);
//	deQueue(Q); printQueue(Q); getchar();
//	deQueue(Q); printQueue(Q); getchar();
//	deQueue(Q); printQueue(Q); getchar();
//	deQueue(Q); printQueue(Q); getchar();
//	deQueue(Q); printQueue(Q); getchar();
//}