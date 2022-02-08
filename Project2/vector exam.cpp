#include <iostream>
#include <vector>
using namespace std;


class Cat {
public : 
	explicit Cat(int age) : mAge{ age } {}
	void speak() const {
		cout << "meow!" << mAge << endl;
	}
private:
	int mAge;
};

void m1() {
	vector<int> nums{ 0,1,2,3,4 };
	vector<Cat> cats;
	nums.emplace_back(5);

	for (size_t idx = 0; idx < nums.size(); idx++) 
	{
		cout << nums[idx] << endl;
	}

	for (auto itr = nums.begin(); itr < nums.end(); itr++)
	{
		cout << (*itr) << endl;
	}

	for (const int& num : nums) {
		cout << num << endl;
	}

	cats.emplace_back(Cat(1));
	cats.emplace_back(Cat(2));
	cats.emplace_back(Cat(3));
	cats.emplace_back(Cat(4));

	for (const auto& cat : cats) {
		cat.speak();
	}

}

#include <iostream>
#include <vector>
using namespace std;

class Cat1 {
public : 
	Cat1(string name, int age) :
		mName{ move(name) }, mAge{ age }{};
	void speak() const {
			cout << "meow" << mAge << endl;
	}
private:
	string mName;
	int mAge;
};

void m2()
{
	vector<Cat1> cats;
	cats.emplace_back( "cat0", 0);
	cats.emplace_back( "cat1", 1);
	cats.emplace_back("kitty", 2 );
	Cat1 nabi{ "nabi", 3 };
	cats.emplace_back(move(nabi));
	for (const auto& cat : cats) {
		cat.speak();
	}
}