#include <iostream>
#include <string>
#include <unordered_map>
#define endl '\n'

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, m;
	std::cin >> n >> m;

	std::unordered_map<std::string, std::string> strIntMap;
	std::unordered_map<std::string, std::string> intStrMap;

	for (int i = 0; i < n; ++i)
	{
		std::string name;
		std::cin >> name;
		strIntMap.insert({ name, std::to_string(i + 1) });
		intStrMap.insert({ std::to_string(i + 1), name });
	}

	for (int i = 0; i < m; ++i)
	{
		std::string id;
		std::cin >> id;

		if (id[0] < 65)
			std::cout << intStrMap[id] << endl;
		else							  
			std::cout << strIntMap[id] << endl;
	}
}