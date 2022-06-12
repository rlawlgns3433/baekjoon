#include <iostream>
#include <stack>
#include <vector>
#define endl '\n'
#define FIO (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0))
using namespace std;

class Tower
{
	
public : 
	int index, height, target_tower_index;

	Tower(int index, int height)
	{
		this->index = index; 
		this->height = height;
	}

	void setTargetTowerIndex(int target_tower_index)
	{
		this->target_tower_index = target_tower_index;
	}

	int getTargetTowerIndex()
	{
		return this->target_tower_index;
	}

};

void findTargetTowers(vector<Tower>& towers)
{
	stack<Tower> stk;

	for (int i = 0; i < towers.size(); i++)
	{
		Tower& t = towers[i];

		int target_tower_index = 0;

		while (stk.empty() == false && stk.top().height < t.height)
		{
			stk.pop();
		}

		if (stk.size() > 0)
		{
			target_tower_index = stk.top().index;
		}
		t.setTargetTowerIndex(target_tower_index);
		stk.push(t);
	}
}

int main()
{
	FIO;
	int n;
	cin >> n;

	vector<Tower> towers;
	for (int i = 0; i < n; i++)
	{
		int h;
		cin >> h;
		towers.push_back(Tower(i+1,h));
	}

	findTargetTowers(towers);

	for (auto& e : towers)
	{
		cout << e.target_tower_index << ' ';
	}
}