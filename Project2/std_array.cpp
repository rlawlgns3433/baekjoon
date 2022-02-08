#include <array>
#include <iostream>
using namespace std;

void print(array<int, 5> arr) {
	for (const auto& ele : arr) {
		cout << ele ;
		if (ele != arr.size()) cout << ", "; 
	}
}

void a() {
	array<int, 10> arr1;
	arr1[0] = 1;
	cout << "arr1의 첫 원소 : " << arr1[0] << endl;
	array<int, 4> arr2 = { 1,2,3,4 };
	cout << "arr2의 모든 원소 : ";
	for (const auto& arr : arr2) {
		cout << arr << " ";
	}
	cout << endl;
	array<int, 4> arr3 = { 1,2,3,4 };
	try{
	cout << arr3.at(3) << endl;
	cout << arr3.at(4) << endl;
	}
	catch (const out_of_range& ex) {
		cerr << ex.what() << endl;
	}
	/*array<int, 5> arr4;
	for (int i = 0; i < arr4.size(); i++)
		cin >> arr4[i];
	print(arr4);*/

	for (auto it = arr3.begin(); it != arr3.end(); it++) {
		auto element = (*it);
		cout << element << " " ;
	}
	cout << endl;

	cout << arr2.front() << endl;
	cout << arr2.back() << endl;
	cout << *(arr2.data() + 1) << endl;


}
