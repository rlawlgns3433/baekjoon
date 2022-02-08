//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <stdlib.h>
//#include <algorithm>
//#include <string.h>
//using namespace std;
//
//typedef const char* element;
//// ���� ���� ����Ʈ�� ��� ����
//typedef struct listnode* listpointer;
//typedef struct listnode {
//	listpointer llink;
//	char data[10];
//	listpointer rlink;
//}listnode;
////��� ���
//typedef struct listhead {
//	listpointer head;
//}listhead;
////���� ���� ���� ����Ʈ ����
//listhead* createDoubleLinkedListHead() {
//	listhead* h = (listhead*)malloc(sizeof(listhead));
//	h->head = NULL;
//	return h;
//}
////���� ���� ����Ʈ ���
//void printlist(listhead *h) {
//	listpointer p = h->head;
//	while (p != NULL) {
//		cout << p->data << " ";
//		p = p->rlink;
//		if (p != NULL) cout << ", ";
//	}
//}
////pre �ڿ� ��带 ����
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
////���� ���� ����Ʈ���� old ��带 ����
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
////����Ʈ���� x��带 Ž��
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
////	cout << "���� ���� ����Ʈ �����ϱ�! " << endl;
////	printlist(h); getchar();
////
////	cout << "���� ���Ḯ��Ʈ�� [��] ��� �����ϱ�!" << endl;
////	insertMiddleNode(h, NULL, "��");
////	printlist(h); getchar();
////
////	cout << "���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�!" << endl;
////	p = searchnode(h, "��"); insertMiddleNode(h, p, "��");
////	printlist(h); getchar();
////
////	cout << "���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�!" << endl;
////	p = searchnode(h, "��"); insertMiddleNode(h, p, "��");
////	printlist(h); getchar();
////
////	cout << "���� ���� ����Ʈ���� [��] ��� �����ϱ�!" << endl;
////	p = searchnode(h, "��"); deletenode(h,p);
////	printlist(h); getchar();
////}