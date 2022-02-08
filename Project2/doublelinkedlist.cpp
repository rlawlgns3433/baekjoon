//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <stdlib.h>
//#include <algorithm>
//#include <string.h>
//using namespace std;
//
//typedef const char* element;
//// 이중 연결 리스트의 노드 구조
//typedef struct listnode* listpointer;
//typedef struct listnode {
//	listpointer llink;
//	char data[10];
//	listpointer rlink;
//}listnode;
////헤드 노드
//typedef struct listhead {
//	listpointer head;
//}listhead;
////공백 이중 연결 리스트 생성
//listhead* createDoubleLinkedListHead() {
//	listhead* h = (listhead*)malloc(sizeof(listhead));
//	h->head = NULL;
//	return h;
//}
////이중 연결 리스트 출력
//void printlist(listhead *h) {
//	listpointer p = h->head;
//	while (p != NULL) {
//		cout << p->data << " ";
//		p = p->rlink;
//		if (p != NULL) cout << ", ";
//	}
//}
////pre 뒤에 노드를 삽입
//void insertMiddleNode(listhead *h, listnode* pre, element item) {
//	listnode* newnode = (listnode*)malloc(sizeof(listnode));
//	strcpy(newnode->data, item);
//	if (h->head == NULL) {
//		newnode->rlink = NULL;
//		h->head = newnode;
//	}
//	else if (pre->rlink == NULL) {
//		newnode->rlink = NULL;
//		pre->rlink = newnode;
//		newnode->llink = pre;
//	}
//	else {
//		newnode->rlink = pre->rlink;
//		pre->rlink = newnode;
//		newnode->llink = pre;
//	}
//}
////이중 연결 리스트에서 old 노드를 삭제
//element deletenode(listhead *h, listnode* old) {
//	element temp;
//	if (h->head == NULL) return 0;
//	else if (old == NULL) return 0;
//	else {
//		temp = old->data;
//		old->llink->rlink = old->rlink;
//		old->rlink->llink = old->llink;
//		free(old);
//		return temp;
//	}
//}
////리스트에서 x노드를 탐색
//listnode* searchnode(listhead *h, element item) {
//	listnode *p = h->head;
//	while (p != NULL) {
//		if (strcmp(p->data, item) == 0)
//			return p;
//		else p = p->rlink;
//	}
//	return p;
//}
//
////
////int main()
////{
////	listhead *h = createDoubleLinkedListHead();
////	listnode* p;
////	cout << "이중 연결 리스트 생성하기! " << endl;
////	printlist(h); getchar();
////
////	cout << "이중 연결리스트의 [월] 노드 삽입하기!" << endl;
////	insertMiddleNode(h, NULL, "월");
////	printlist(h); getchar();
////
////	cout << "이중 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기!" << endl;
////	p = searchnode(h, "월"); insertMiddleNode(h, p, "수");
////	printlist(h); getchar();
////
////	cout << "이중 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기!" << endl;
////	p = searchnode(h, "수"); insertMiddleNode(h, p, "금");
////	printlist(h); getchar();
////
////	cout << "이중 연결 리스트에서 [수] 노드 삭제하기!" << endl;
////	p = searchnode(h, "수"); deletenode(h,p);
////	printlist(h); getchar();
////}