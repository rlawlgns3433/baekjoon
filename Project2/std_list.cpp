#include <iostream>
#include <list>
using namespace std;


void l1()
{
	list<int> list1 = { 1,2,3,4,5 };
	for (const auto& ele : list1)
		cout << ele << " ";
	cout << endl;
	list1.push_back(6);
	for (const auto& ele : list1)
		cout << ele << " ";
	cout << endl;
	list1.emplace(next(list1.begin()), 0);
	for (const auto& ele : list1)
		cout << ele << " ";
	cout << endl;
	list1.emplace(list1.end(), 7);
	for (const auto& ele : list1)
		cout << ele << " ";
	cout << endl;
	list1.pop_back();
	for (const auto& ele : list1)
		cout << ele << " ";
	cout << endl;

	list1.sort();
	for (const auto& ele : list1)
		cout << ele << " ";
	cout << endl;

	list1.sort(greater<int>());
	for (const auto& ele : list1)
		cout << ele << " ";
	cout << endl;

	list1.sort(less<int>());
	for (const auto& ele : list1)
		cout << ele << " ";
	cout << endl;
	cout << list1.size() << endl;

}