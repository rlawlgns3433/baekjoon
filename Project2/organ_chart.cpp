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
//			cout << manager << "�� ã�� �� �����ϴ�.\n";
//			return false;
//		}
//
//		if (managerNode->first && managerNode->second) {
//			cout << manager << " �Ʒ��� " << subordinate << "�� �߰��� �� �����ϴ�. \n";
//			return false;
//		}
//		if (!managerNode->first) managerNode->first = new node{ subordinate, NULL, NULL };
//		else managerNode->second = new node{ subordinate, NULL, NULL };
//		cout << manager << " �Ʒ��� " << subordinate << "��(��) �߰��߽��ϴ�.\n";
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
//	tree.addSubordinate("CEO", "�λ���"); 
//	tree.addSubordinate("�λ���", "IT����");
//	tree.addSubordinate("�λ���", "�����ú���"); 
//	tree.addSubordinate("IT����", "��������");
//	tree.addSubordinate("IT����", "�۰�������");
//	tree.addSubordinate("�����ú���", "��������");
//	tree.addSubordinate("�����ú���", "ȫ������");
//
//	cout << "\n";
//	org_tree::preorder(tree.root); cout << "\n";
//	org_tree::inorder(tree.root); cout << "\n";
//	org_tree::postorder(tree.root); cout << "\n";
//	org_tree::levelorder(tree.root); cout << "\n";
//
//}