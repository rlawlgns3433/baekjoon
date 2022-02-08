//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//float coef;
//typedef struct listnode* listpointer;
//typedef struct listnode {
//	float coef;
//	int expo;
//	listpointer link;
//};
//
//typedef struct listhead {
//	listpointer head;
//};
//
//listhead* createLinkedList() {
//	listhead* L = (listhead*)malloc(sizeof(listhead));
//	L->head = NULL;
//	return L;
//}
//
//void appendTerm(listhead* L, float coef, int expo) {
//	listnode* newnode = (listnode*)malloc(sizeof(listnode));
//	listnode* p;
//	newnode->coef = coef;
//	newnode->expo = expo;
//	newnode->link = NULL;
//	if (L->head == NULL) {
//		L->head = newnode;
//	}
//	else {
//		p = L->head;
//		while (p->link != NULL)
//			p = p->link;
//		p->link = newnode;
//	}
//}
//
//void addp(listhead* A, listhead* B, listhead* C) {
//	listpointer pA = A->head;
//	listpointer pB = B->head;
//	float sum;
//	while (pA && pB) {
//		if (pA->expo == pB->expo) {
//			sum = pA->coef + pB->coef;
//			appendTerm(C, sum, pA->expo);
//			pA = pA->link; pB = pB->link;
//		}
//		else if (pA->expo > pB->expo) {
//			appendTerm(C, pA->coef, pA->expo);
//			pA = pA->link;
//		}
//		else {
//			appendTerm(C, pB->coef, pB->expo);
//			pB = pB->link;
//		}
//	}
//	while (pA) {
//		appendTerm(C, pA->coef, pA->expo);
//		pA = pA->link;
//	}
//	while (pB) {
//		appendTerm(C, pB->coef, pB->expo);
//		pB = pB->link;
//	}
//}
//
//void printpoly(listhead* L) {
//	listpointer p = L->head;
//	for (; p; p = p->link) {
//		printf("%3.0fx^%d", p->coef, p -> expo);
//		if (p->link != NULL) printf(" + ");
//	}
//	printf("\n");
//}
//
//int main()
//{
//	listhead* A = createLinkedList();
//	listhead* B = createLinkedList();
//	listhead* C = createLinkedList();
//
//	appendTerm(A, 2, 3);
//	appendTerm(A, 4, 2);
//	appendTerm(A, 6, 1);
//	appendTerm(A, 3, 0);
//	appendTerm(B, 7, 4);
//	appendTerm(B, 3, 3);
//	appendTerm(B, 5, 2);
//	appendTerm(B, 9, 1);
//	printpoly(A);
//	printpoly(B);
//	addp(A, B, C);
//	printpoly(C);
//}