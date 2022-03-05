//#include <iostream>
//using namespace std;
//
//typedef struct Node* Nodepointer;
//typedef struct Node {
//	int data;
//	Nodepointer left_child, right_child;
//};
//
//Node* insert(Node* root, int data) {
//	if (root == NULL) {
//		root = new Node();
//		root->data = data;
//		root->left_child = root->right_child = NULL;
//	}
//	else if (data <= root->data)
//		root->left_child = insert(root->left_child, data);
//	else root->right_child = insert(root->right_child, data);
//	return root;
//}
//
//void postorder(Node* root) {
//	if (root->left_child != NULL)
//		postorder(root->left_child);
//	if (root->right_child != NULL)
//		postorder(root->right_child);
//	cout << root->data << '\n';
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	int n;
//	Node* root = NULL;
//	while (cin >> n) {
//		root = insert(root, n);
//	}
//	postorder(root);
//}