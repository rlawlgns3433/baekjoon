/// <summary>
/// 1068¹ø Æ®¸®
/// </summary>
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> t_map[51];

int dfs(int root)
{
    int leaf_node = 1, child_node = 0;
    for (auto child : t_map[root])
    {
        if (child == K) continue;
        child_node += dfs(child);
    }
    if (child_node) return child_node;
    else return leaf_node;
}

int main()
{
    cin >> N;
    int root = 0;
    for (int i = 0; i < N; i++)
    {
        int parent;
        cin >> parent;
        if (parent == -1) root = i;
        else t_map[parent].emplace_back(i);
    }

    cin >> K;
    if (root == K) cout << 0;
    else cout << dfs(root);
}