//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_QUEUE_SIZE 100
//
//typedef char element;
//
//typedef struct queueType {
//	element queue[MAX_QUEUE_SIZE];
//	int front, rear;
//};
//
//queueType* createQueue() {
//	queueType* cQ = (queueType*)malloc(sizeof(queueType));
//	cQ->front = 0;
//	cQ->rear = 0;
//	return cQ;
//}
//
//int isEmpty(queueType* cQ) {
//	if (cQ->front == cQ->rear)
//		return 1;
//	else return 0;
//}
//
//int isFull(queueType* cQ) {
//	if ((cQ->rear + 1) % MAX_QUEUE_SIZE == cQ->front)
//		return 1;
//	else return 0;
//}
//
//void addq(queueType* cQ, element item) {
//	if (isFull(cQ)) fprintf(stderr, "queue is full\n");
//	else {
//		cQ->rear += 1;
//		cQ->queue[cQ->rear] = item;
//	}
//}
//
//element deleteq(queueType* cQ) {
//	if (isEmpty(cQ)) {
//		fprintf(stderr, "queue is empty\n");
//		exit(1);
//	}
//	else {
//		cQ->front += 1;
//		return cQ->queue[cQ->front];
//	}
//}
//
//void printQ(queueType* cQ) {
//	int i;
//	printf("Queue : [");
//	for (i = cQ->front + 1; i <= cQ->rear; i++) {
//		printf("%c ", cQ->queue[i]);
//	}
//	printf("]");
//}
//
//element peek(queueType* cQ) {
//	if (isEmpty(cQ)) fprintf(stderr, "queue is empty\n");
//	else return cQ->queue[cQ->front + 1];
//}
//
//int main()
//{
//	queueType* cQ = createQueue();
//	element item;
//	addq(cQ, 'a'); printQ(cQ); getchar();
//	addq(cQ, 'b'); printQ(cQ); getchar();
//	addq(cQ, 'c'); printQ(cQ); getchar();
//	deleteq(cQ); printQ(cQ); getchar();
//	deleteq(cQ); printQ(cQ); getchar();
//	item = peek(cQ); printf("\npeek : %c\n", item);
//	deleteq(cQ); printQ(cQ); getchar();
//	deleteq(cQ); printQ(cQ); getchar();
//}