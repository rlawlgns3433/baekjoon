#include <iostream>
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