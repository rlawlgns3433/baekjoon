#include <iostream>
#include <deque>
using namespace std;

void d()
{
	deque<int> deq = { 1,2,3,4,5 };
	for (const auto& ele : deq)
		cout << ele << " ";
	cout << endl;
	deq.push_front(0);
	for (const auto& ele : deq)
		cout << ele << " ";
	cout << endl;
	deq.push_back(6);
	for (const auto& ele : deq)
		cout << ele << " ";
	cout << endl;
	deq.emplace(deq.begin() + 2, 10);
	for (const auto& ele : deq)
		cout << ele << " ";
	cout << endl;
	deq.pop_back();
	for (const auto& ele : deq)
		cout << ele << " ";
	cout << endl;
	deq.pop_front();
	for (const auto& ele : deq)
		cout << ele << " ";
	cout << endl;
	deq.erase(deq.begin() + 1);
	for (const auto& ele : deq)
		cout << ele << " ";
	cout << endl;
	deq.erase(deq.begin() + 3, deq.end());
	for (const auto& ele : deq)
		cout << ele << " ";
	cout << endl;

}
