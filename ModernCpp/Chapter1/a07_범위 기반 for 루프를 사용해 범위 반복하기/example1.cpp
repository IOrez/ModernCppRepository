#include <iostream>
#include <vector>
#include <map>

std::vector<int> getRates()
{
	return std::vector<int>{1, 1, 2, 3, 5, 8, 13};
}

std::multimap<int, bool> getRates2()
{
	return std::multimap<int, bool>{
		{ 1, true },
		{ 1,true },
		{ 2,false },
		{ 3,true },
		{ 5,true },
		{ 8,false },
		{ 13,true }
	};
}

int main()
{

	//시퀀스의 요소에 특정 타입 커밋
	auto rates = getRates();
	for (int rate : rates)
		std::cout << rate << std::endl;


	for (int& rate : rates)
		rate *= 2;

	//타입을 지정하지 않고 컴파일러가 추론하도록 함
	for (auto&& rate : getRates())
		std::cout << rate << std::endl;

	for (auto& rate : rates)
		rate *= 2;

	for (auto const& rate : rates)
		std::cout << rate << std::endl;


	//C++에서 구조화된 바인딩 및 분해(decomposition) 선언을 사용
	for (auto&& [rate, flag] : getRates2())
		std::cout << rate << std::endl;

}