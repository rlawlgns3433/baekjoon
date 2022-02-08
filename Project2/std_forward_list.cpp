#include <iostream>
#include <string>
#include <forward_list>
using namespace std;

void f1()
{
	forward_list<int> fwd_list = { 1,2,3 };
	for (const auto& ele : fwd_list)
		cout << ele << " ";
	cout << endl;
	fwd_list.push_front(0);
	for (const auto& ele : fwd_list)
		cout << ele << " ";
	cout << endl;
	auto it = fwd_list.begin();
	fwd_list.insert_after(it, 5);
	for (const auto& ele : fwd_list)
		cout << ele << " ";
	cout << endl;
	fwd_list.insert_after(it, 6);
	for (const auto& ele : fwd_list)
		cout << ele << " ";
	cout << endl;

	fwd_list.erase_after(fwd_list.begin());
	for (const auto& ele : fwd_list)
		cout << ele << " ";
	cout << endl;
	fwd_list.erase_after(fwd_list.begin(), fwd_list.end());
	for (const auto& ele : fwd_list)
		cout << ele << " ";
	cout << endl;
	fwd_list.pop_front();
	for (const auto& ele : fwd_list)
		cout << ele << " ";
	cout << endl;
		
}

struct citizen
{
	string name;
	int age;
};

ostream& operator<<(ostream& os, const citizen& c) {
	return (os << "[" << c.name << ", " << c.age << "]");
} 

void f2()
{
	forward_list<citizen> citizens = {
		{ "Kim", 22}, {"Lee", 25}, {"park", 18},{"Jin", 16}
	};

	auto citizens_copy = citizens; //deep copy

	cout << "전체 시민들 : ";
	for (const auto& citizen : citizens)
		cout << citizen << " ";
	cout << endl;

	citizens.remove_if([](const citizen& c) {
		return (c.age < 19);
	});

	cout << "투표권이 있는 시민들 : ";
	for (const auto& citizen : citizens)
		cout << citizen << " ";
	cout << endl;

	citizens_copy.remove_if([](const citizen& c) {
		return (c.age != 18);
	});

	cout << "내년에 투표권이 생기는 시민들 : ";
	for (const auto& citizen : citizens_copy)
		cout << citizen << endl;
	cout << endl;

	forward_list<int> fwd_list1 = { 23,0,1,-3,34,32 };
	fwd_list1.sort(greater<int>());
	for (const auto& ele : fwd_list1){
		cout << ele << " ";
	}
	cout << endl;

	fwd_list1.reverse();
	for (const auto& ele : fwd_list1)
		cout << ele << " ";
	cout << endl;

	fwd_list1.clear();
	for (const auto& ele : fwd_list1)
			cout << ele << " ";
	cout << endl;
	
	fwd_list1 = { 0,1,0,1,-1,10,5,5,10,0};
	fwd_list1.unique();
	for (const auto& ele : fwd_list1)
		cout << ele << " ";
	cout << endl;

	fwd_list1.sort();
	fwd_list1.unique();
	for (const auto& ele : fwd_list1)
		cout << ele << " ";
	cout << endl;

	fwd_list1 = { 0,1,0,1,-1,10,5,5,10,0 };
	fwd_list1.sort();
	fwd_list1.unique([](int a, int b) {return (b - a) < 2; });
	for (const auto& ele : fwd_list1)
		cout << ele << " ";
}


void f3(){
	forward_list<int> list = { 1,3,5,7};
	auto it = list.begin();
	list.remove(*it);
	for (const auto& ele : list)
		cout << ele << ' ';
}