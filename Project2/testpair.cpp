/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef char element;

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
	element item;
	stacknode* p = top;
	if (isEmpty()) {
		fprintf(stderr, "stack is empty");
		exit(1);
	}
	else {
		item = p->data;
		top = p->link;
		free(p);
		return item;
	}
}

element peek() {
	if (isEmpty()) {
		fprintf(stderr, "stack is emtpy");
		exit(1);
	}
	else return (top->data);
}

int testpair(const char *exp) {
	int i, length = strlen(exp);
	char open_pair, symbol;
	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) {
		case '(' :
		case '{':
		case '[': push(symbol); break;
		case ')':
		case '}':
		case ']': 
			if (top == NULL) return 0;
			else {
				open_pair = pop();
				if ((open_pair == '(' && symbol != ')') ||
					(open_pair == '{' && symbol != '}') ||
					(open_pair == '[' && symbol != ']'))
					return 0;
				else break;
			}
		}
	}
	if (top == NULL) return 1;
	else return 0;
}

int main()
{
	const char* exp = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";
	printf("%s", exp);

	if (testpair(exp) == 1)
		printf("\ncorrect expression\n");
	else
		printf("\nincorrect expression\n");
	getchar();

	int n;
	char *str = (char*)malloc(sizeof(char)*1000);
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", str);
		if (testpair(str) == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}*/