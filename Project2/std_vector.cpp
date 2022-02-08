#include <iostream>
#include <vector>
using namespace std;

void v()
{
	vector<int> vec;
	vec.push_back(1);
	for (const auto& ele : vec)
		cout << ele << " ";
	cout << endl;
	vec.push_back(2);
	for (const auto& ele : vec)
		cout << ele << " ";
	cout << endl;
	vec.insert(vec.begin(), 0);
	for (const auto& ele : vec)
		cout << ele << " ";
	cout << endl;
	vec.insert(find(vec.begin(), vec.end(), 1), 4);
	for (const auto& ele : vec)
		cout << ele << " ";
	cout << endl;
	vector<int> vec1 = { 1,5,6,7,8 };
	vec1.erase(vec1.begin() + 1, vec1.begin() + 4);
	for (const auto& ele : vec1)
		cout << ele << " ";
	cout << endl;
	vec1.clear();
	for (const auto& ele : vec1)
		cout << ele << " ";
	cout << endl;
}