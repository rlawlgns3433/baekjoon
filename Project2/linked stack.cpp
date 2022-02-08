/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct stacknode* stackpointer;
typedef struct stacknode {
	element data;
	stackpointer link;
}stacknode;

stackpointer top = NULL;

int isEmpty()
{
	if (top == NULL) return 1;
	else return 0;
}

void push(element item) {
	stacknode* newnode = (stacknode*)malloc(sizeof(stacknode));
	newnode->data = item;
	newnode->link = top;
	top = newnode;
}

element pop() {
	element temp;
	stacknode *p = top;

	if (isEmpty()) {
		fprintf(stderr, "stack is empty\n");
		exit(1);
	}
	else {
		temp = p->data;
		top = p->link;
		free(p);
		return temp;
	}
}

element peek() {
	if (isEmpty()) {
		fprintf(stderr, "stack is empty\n");
		exit(1);
	}
	else {
		return (top->data);
	}
}

void printstack() {
	stackpointer p = top;
	printf("stack [");
	for (; p; p = p->link)
		printf("%d ", p->data);
	printf("]\n");
}

int main()
{
	element item;
	printstack(); getchar();
	push(1); printstack(); getchar();
	push(2); printstack(); getchar();
	push(3); printstack(); getchar();
	item = peek(); printf("peek : %d\n", item); getchar();
	pop(); printstack(); getchar();
	pop(); printstack(); getchar();
	pop(); printstack(); getchar();
	pop(); printstack(); getchar();

}*/