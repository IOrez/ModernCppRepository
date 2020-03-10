#include <iostream>
#include <string>
#include <map>

int main()
{
	std::map<int, std::string> m;
	auto result = m.insert({ 1,"one" });
	std::cout << "inserted = " << result.second << std::endl;
	std::cout << "value = " << result.first->second << std::endl;

	std::map<int, std::string>::iterator it;
	bool inserted;

	std::tie(it, inserted) = m.insert({ 2,"two" });
	std::cout << "inserted = " << inserted << std::endl
		<< "value = " << it->second << std::endl;

	std::tie(it, inserted) = m.insert({ 3,"three" });
	std::cout << "inserted = " << inserted << std::endl
		<< "value = " << it->second << std::endl;


	{
		auto [iter, isInserted] = m.insert({ 4,"four" });
		std::cout << "inserted = " << isInserted << std::endl
			<< "value = " << iter->second << std::endl;
	}

	{
		if (auto [iter, isInserted] = m.insert({ 5,"five" }); isInserted)
		{
			std::cout << iter->second << std::endl;
		}
	}

}