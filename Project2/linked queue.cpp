//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef char element;
//typedef struct Qnode {
//	element data;
//	struct Qnode* link;
//}Qnode;
//
//typedef struct queueType {
//	Qnode* front, *rear;
//}queueType;
//
//queueType* createQueue() {
//	queueType* LQ = (queueType*)malloc(sizeof(queueType));
//	LQ->front = NULL;
//	LQ->rear = NULL;
//	return LQ;
//}
//
//int isEmpty(queueType* LQ) {
//	if (LQ->front == NULL) return 1;
//	else return 0;
//}
//
//void addq(queueType* LQ, element item) {
//	Qnode* newNode = (Qnode*)malloc(sizeof(Qnode));
//	newNode->data = item;
//	if (isEmpty(LQ)) {
//		LQ->front = newNode;
//		LQ->rear = newNode;
//		newNode->link = NULL;
//	}
//	else {
//		LQ->rear->link = newNode;
//		newNode->link = NULL;
//		LQ->rear = newNode;
//	}
//}
//
//element deleteq(queueType* LQ) {
//	element item;
//	Qnode* p = LQ->front;
//	if (isEmpty(LQ)) {
//		fprintf(stderr, "queue is empty\n");
//		exit(1);
//	}
//	else {
//		item = p->data;
//		LQ->front = p->link;
//		free(p);
//		return item;
//	}
//}
//
//element peek(queueType* LQ) {
//	if (isEmpty(LQ)) exit(1);
//	else return LQ->front->data;
//}
//
//void printQ(queueType* LQ) {
//	printf("queue : [");
//	Qnode* p = LQ->front;
//	while (p) {
//		printf("%c ", p->data);
//		p = p->link;
//	}
//	printf("]");
//}
//
//int main()
//{
//	element item;
//	queueType* LQ = createQueue();
//	printQ(LQ); getchar();
//	addq(LQ, 'A'); printQ(LQ); getchar();
//	addq(LQ, 'B'); printQ(LQ); getchar();
//	addq(LQ, 'C'); printQ(LQ); getchar();
//	addq(LQ, 'D'); printQ(LQ); getchar();
//	item = peek(LQ); printf("\npeek : %c", item); getchar();
//	deleteq(LQ); printQ(LQ); getchar();
//	deleteq(LQ); printQ(LQ); getchar();
//	deleteq(LQ); printQ(LQ); getchar();
//}