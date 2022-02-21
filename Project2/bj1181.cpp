#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct listnode* listpointer;

typedef struct listnode {
	string data;
	listpointer link;
};

typedef struct listhead {
	listpointer link;
};

listpointer createLinkedList() {
	listnode* L = (listnode*)malloc(sizeof(listnode));
	L->link = NULL;
	return L;
}

bool isEmpty(listpointer L) {
	if (L->link == NULL) {
		return true;
	}
	else false;
}

void addNode(listpointer L, string node) {
	
}

int main()
{
	listpointer L = createLinkedList();
	
}