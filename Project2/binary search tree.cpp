//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef char element;
//typedef struct treeNode* treePointer;
//typedef struct treeNode {
//	element data;
//	treePointer left, right;
//}treeNode;
//
//treeNode* search(treeNode* root, element key) {
//	if (!root) return NULL;
//	if (root->data == key) return root;
//	else if (root->data > key) search(root->left, key);
//	else search(root->right, key);
//}
//
//treeNode* insertNode(treeNode* root, element item) {
//	treeNode* newNode;
//	if (root == NULL) {
//		newNode = (treeNode*)malloc(sizeof(treeNode));
//		newNode->data = item;
//		newNode->left = NULL;
//		newNode->right = NULL;
//		return newNode;
//	}
//	else if (root->data < item) root->right = insertNode(root->right, item);
//	else if (root->data > item) root->left = insertNode(root->left, item);
//	else printf("\n같은 키가 이미 있습니다.");
//
//	return root;
//}
//
//void deleteNode(treeNode* root, element key) {
//	treePointer parent, p, succ, succ_parent;
//	treePointer child;
//	parent = NULL;
//	p = root;
//	while ((p != NULL)&&(p->data != key)) {
//		parent = p;
//		if (key < p->data) p = p->left;
//		else p = p->right;
//	}
//
//	if (p == NULL) {
//		printf("\n 찾는 키가 이진 트리에 없습니다.");
//	}
//
//	if ((p->left == NULL) && (p->right == NULL)) {
//		if (parent != NULL) {
//			if (parent->left == p) parent->left = NULL;
//			else parent->right = NULL;
//		}
//		else root = NULL;
//	}
//	else if ((p->left == NULL) || (p->right == NULL)) {
//		if (p->left == NULL) child = p->left;
//		else child = p->right;
//
//		if (parent != NULL) {
//			if (parent->left == p) parent->left = child;
//			else parent->right = child;
//		}
//		else root = child;
//	}
//	else {
//		succ_parent = p;
//		succ = p->left;
//		while (succ->right != NULL) {
//			succ_parent = succ;
//			succ = succ->right;
//		}
//		if (succ_parent->left == succ) succ_parent->left = succ->left;
//		else succ_parent->right = succ->left;
//		p->data = succ->data;
//		p = succ;
//	}
//	free(p);
//}
