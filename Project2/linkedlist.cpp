//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <stdlib.h>
//#include <algorithm>
//#include <string.h>
//using namespace std;
//
//typedef struct ListNode* ListPointer;
//
//typedef struct ListNode {
//	char data[200];
//	ListPointer link;
//}ListNode;
//
//typedef struct ListHead {
//	ListPointer head;
//}ListHead;
//
//ListHead* createLinkedListHead() {
//	ListHead* h = (ListHead*)malloc(sizeof(ListHead));
//	h->head = NULL;
//	return h;
//}
//
//int isEmpty(ListHead *h) {
//	if (h->head == NULL)
//		return 1;
//	else return 0;
//}
//
////전체 메모리 해제
//void freeLinkedList(ListHead *h) {
//	ListPointer p = h->head;
//	while (h->head != NULL) {
//		p = h->head;
//		h->head = h->head->link;
//		free(p);
//		p = NULL;
//	}
//}
//
//void printList(ListHead *h) {
//	ListPointer p = h->head;
//	while (p != NULL) {
//		cout << p->data << " ";
//		p = p->link;
//		if (p != NULL) printf(", ");
//	}
//}
//
////첫 번째 노드로 삽입
//void insertFirstNode(ListHead* h, const char* item) {
//	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
//	strcpy(newNode->data, item);
//	newNode->link = h->head;
//	h->head = newNode;
//}
//
////노드를 pre 뒤에 삽입
//void insertMiddleNode(ListHead* h, ListNode* pre, const char* item) {
//	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
//	strcpy(newNode->data, item);
//	
//	if (h->head == NULL) {
//		newNode->link = NULL;
//		h->head = newNode;
//	}
//	else if (pre->link == NULL) {
//		pre->link = newNode;
//		newNode->link = NULL;
//	}
//	else {
//		newNode->link = pre->link;
//		pre->link = newNode;
//	}
//}
////마지막 노드로 삽입
//void insertLastNode(ListHead* h, const char* item) {
//	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
//	ListPointer p;
//	strcpy(newNode->data, item);
//	newNode->link = NULL;
//
//	if (h->head == NULL) 
//		h->head = newNode;
//	else{
//		p = h->head;
//		while (p->link != NULL)
//			p = p->link;
//		p->link = newNode;
//	}
//}
//
//int main()
//{
//	ListHead* h = createLinkedListHead();
//	insertFirstNode(h, "hello");
//	insertFirstNode(h, "world");
//	insertMiddleNode(h, h->head, "program");
//	insertLastNode(h, "hihi");
//	printList(h);
//	printf("\nfree Linked List");
//	freeLinkedList(h);
//	printf("\n");
//	insertFirstNode(h, "world");
//	insertMiddleNode(h, h->head, "hello");
//	printList(h);
//}