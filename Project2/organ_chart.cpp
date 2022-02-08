//#include <iostream>
//#include <queue>
//#include <string>
//using namespace std;
//
//typedef struct node* nodepointer;
//struct node {
//	string position;
//	nodepointer first;
//	nodepointer second;
//};
//
//struct org_tree {
//	nodepointer root;
//	static org_tree create_org_structure(const string& pos) {
//		org_tree tree;
//		tree.root = new node{ pos, NULL, NULL };
//		return tree;
//	}
//
//	static nodepointer find(nodepointer root, const string& value) {
//		if (root == NULL)
//			return NULL;
//		
//		if (root->position == value)
//			return root;
//		
//		auto firstFound = org_tree::find(root->first, value);
//		if (firstFound != NULL)
//			return firstFound;
//
//		return org_tree::find(root->second, value);
//	}
//
//	bool addSubordinate(const string& manager, const string& subordinate) {
//		auto managerNode = find(root, manager);
//
//		if (!managerNode)
//		{
//			cout << manager << "을 찾을 수 없습니다.\n";
//			return false;
//		}
//
//		if (managerNode->first && managerNode->second) {
//			cout << manager << " 아래에 " << subordinate << "을 추가할 수 없습니다. \n";
//			return false;
//		}
//		if (!managerNode->first) managerNode->first = new node{ subordinate, NULL, NULL };
//		else managerNode->second = new node{ subordinate, NULL, NULL };
//		cout << manager << " 아래에 " << subordinate << "을(를) 추가했습니다.\n";
//		return true;
//	}
//
//	static void preorder(node* root) {
//		if (root) {
//			cout << root->position << " ";
//			preorder(root->first);
//			preorder(root->second);
//		}
//	}
//
//	static void inorder(node* root) {
//		if (root) {
//			inorder(root->first);
//			cout << root->position << " ";
//			inorder(root->second);
//		}
//	}
//
//	static void postorder(node* root) {
//		if (root) {
//			postorder(root->first);
//			postorder(root->second);
//			cout << root->position << " ";
//		}
//	}
//
//	static void levelorder(node* root) {
//		if (!root) return;
//		queue<node*> q;
//		q.push(root);
//
//		while (!q.empty()) {
//			int size = q.size();
//			for (int i = 0; i < size; i++) {
//				auto current = q.front();
//				q.pop();
//
//				cout << current->position << ", ";
//				if (current->first) q.push(current->first);
//				if (current->second) q.push(current->second);
//			}
//			cout << endl;
//		}
//	}
//};
//
//
//
//int main()
//{
//	auto tree = org_tree::create_org_structure("CEO");
//
//	tree.addSubordinate("CEO", "부사장"); 
//	tree.addSubordinate("부사장", "IT부장");
//	tree.addSubordinate("부사장", "마케팅부장"); 
//	tree.addSubordinate("IT부장", "보안팀장");
//	tree.addSubordinate("IT부장", "앱개발팀장");
//	tree.addSubordinate("마케팅부장", "물류팀장");
//	tree.addSubordinate("마케팅부장", "홍보팀장");
//
//	cout << "\n";
//	org_tree::preorder(tree.root); cout << "\n";
//	org_tree::inorder(tree.root); cout << "\n";
//	org_tree::postorder(tree.root); cout << "\n";
//	org_tree::levelorder(tree.root); cout << "\n";
//
//}