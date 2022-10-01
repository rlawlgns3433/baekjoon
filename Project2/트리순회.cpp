#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
	char left, right;
};

node* arr;

void preorder(char root)
{
	if (root == '.') return;
	cout << root;
	preorder(arr[root].left);
	preorder(arr[root].right);
}

void inorder(char root)
{
	if (root == '.')return;
	inorder(arr[root].left);
	cout << root;
	inorder(arr[root].right);
}

void postorder(char root)
{
	if (root == '.') return;
	postorder(arr[root].left);
	postorder(arr[root].right);
	cout << root;
}

int main()
{
	int n;
	cin >> n;
	arr = new node[n];
	for (int i = 0; i < n; i++)
	{
		char d, l, r;
		cin >> d >> l >> r;
		arr[d].left = l;
		arr[d].right = r;
	}

	preorder('A'); cout << endl;
	inorder('A'); cout << endl;
	postorder('A'); cout << endl;
}

//typedef struct node* treePointer;
//typedef struct node {
//	int data;
//	treePointer leftChild, rightChild;
//}node;
//
//treePointer makeRootNode(char data, treePointer leftChild, treePointer rightChild)
//{
//	treePointer root = (treePointer)malloc(sizeof(node));
//	root->data = data;
//	root->leftChild = leftChild;
//	root->rightChild = rightChild;
//
//	return root;
//}
//
//void inorder(treePointer ptr)
//{
//	if (ptr->data) {
//		printf("%d", ptr->data);
//		inorder(ptr->leftChild);
//		inorder(ptr->rightChild);
//	}
//}
//
//void preorder(treePointer ptr)
//{
//	if (ptr->data)
//	{
//		printf("%d", ptr->data);
//		preorder(ptr->leftChild);
//		preorder(ptr->rightChild);
//	}
//}
//
//void postorder(treePointer ptr)
//{
//	if (ptr->data)
//	{
//		postorder(ptr->leftChild);
//		postorder(ptr->rightChild);
//		printf("%d", ptr->data);
//	}
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	treePointer tree = new node[n];
//	for (int i = 0; i < n; i++)
//	{
//		int d, l, r;
//		scanf("%d %d %d", &d, &l, &r);
//		if (l) tree[d].leftChild = makeRootNode(l, NULL, NULL);
//		if (r) tree[d].rightChild = makeRootNode(r, NULL, NULL);
//	}
//	inorder(tree);
//}