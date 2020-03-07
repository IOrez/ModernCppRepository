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

	//�������� ��ҿ� Ư�� Ÿ�� Ŀ��
	auto rates = getRates();
	for (int rate : rates)
		std::cout << rate << std::endl;


	for (int& rate : rates)
		rate *= 2;

	//Ÿ���� �������� �ʰ� �����Ϸ��� �߷��ϵ��� ��
	for (auto&& rate : getRates())
		std::cout << rate << std::endl;

	for (auto& rate : rates)
		rate *= 2;

	for (auto const& rate : rates)
		std::cout << rate << std::endl;


	//C++���� ����ȭ�� ���ε� �� ����(decomposition) ������ ���
	for (auto&& [rate, flag] : getRates2())
		std::cout << rate << std::endl;

}