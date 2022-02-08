/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define STACK_SIZE 100

typedef int element;

element stack[STACK_SIZE];
int top = -1;

int isEmpty() {
	if (top == -1)return 1;
	else return 0;
}

int isFull() {
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}

void push(element item) {
	if (isFull()) fprintf(stderr, "stack is full\n");
	else stack[++top] = item;
}

element pop() {
	if (isEmpty()) fprintf(stderr, "stack is empty\n");
	else return stack[top--];
}

element peek() {
	if (isEmpty()) {
		fprintf(stderr, "stack is empty\n");
		exit(EXIT_FAILURE);
	}
	else return stack[top];
}

void printstack() {
	int i;
	printf("stack [");
	for (i = 0; i <= top; i++) {
		printf("%d ", stack[i]);
	}
	printf("]");
}

int main()
{
	element item;
	printf("순차 스택 연산 \n");
	getchar();
	printstack(); getchar();
	push(1); printstack(); getchar();
	push(2); printstack(); getchar();
	push(3); printstack(); getchar();
	item = peek(); printf("peek : %d\n", item);
	pop(); printstack(); getchar();
	pop(); printstack(); getchar();
	pop(); printstack(); getchar();
	pop(); printstack(); getchar();

}*/