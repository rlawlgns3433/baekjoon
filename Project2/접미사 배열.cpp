#include <iostream>
#include <vector>
#include <algorithm>

bool Compare(const std::string& left, const std::string& right)
{
	int leftIndex = 0;
	int rightIndex = 0;

	while (left[leftIndex] != '\0' || right[rightIndex] != '\0')
	{
		if (left[leftIndex] == right[rightIndex])
		{
			++leftIndex;
			++rightIndex;
		}
		else if (left[leftIndex] > right[rightIndex])
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	if(left[leftIndex] == '\0')
		return true;
	else if (right[rightIndex] == '\0')
		return false;

	return true;
}

int main()
{
	std::vector<std::string> v;
	std::string S;
	std::cin >> S;

	for (int i = 0; i < S.size(); ++i)
	{
		auto str = S.substr(i, S.size());
		if (str.empty())
			break;

		v.push_back(str);
	}

	std::sort(v.begin(), v.end(), Compare);

	for (auto& e : v)
	{
		std::cout << e << '\n';
	}

	return 0;
}

// baekjoon
