//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef int element;
//typedef struct stackNode* stackPointer;
//typedef struct stackNode {
//	element data;
//	stackPointer link;
//};
//stackPointer top = NULL;
//
//int isEmpty() {
//	if (top == NULL) return 1;
//	else return 0;
//}
//
//void push(element item) {
//	stackNode *newNode = (stackNode*)malloc(sizeof(stackNode));
//	newNode->data = item;
//	newNode->link = top;
//	top = newNode;
//}
//
//element pop() {
//	element item;
//	stackNode* p = top;
//	if (isEmpty()) {
//		fprintf(stderr, "stack is empty\n");
//		exit(1);
//	}
//	else {
//		item = p->data;
//		top = p->link;
//		free(p);
//		return item;
//	}
//}
//
//int evalPostfix(const char *exp) {
//	int opr1, opr2, value, length = strlen(exp);
//	char symbol;
//	for (int i = 0; i < length; i++) {
//		symbol = exp[i];
//		if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/'){
//			value = symbol - '0';
//			push(value);
//		}
//		else {
//			opr2 = pop();
//			opr1 = pop();
//			switch (symbol) {
//			case '+': push(opr1 + opr2); break;
//			case '-': push(opr1 - opr2); break;
//			case '*': push(opr1 * opr2); break;
//			case '/': push(opr1 / opr2); break;
//			}
//		}
//	}
//	return pop();
//}
//
//int main()
//{
//	const char* express = "35*62/-";
//	printf("none evaluated expression : %s\n", express);
//	printf("evaluated expression value : %d\n", evalPostfix(express));
//}