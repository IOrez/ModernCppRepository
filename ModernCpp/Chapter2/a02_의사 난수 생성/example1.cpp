#include <iostream>
#include <random>									//random����� �����Ѵ�.

std::random_device rd{};							//�ǻ糭�������� ����ϱ� ���� std::random_device �����⸦ ����Ѵ�.
auto mtgen = std::mt19937{ rd() };					//��� ������ ���� �� �ϳ��� ����� ���ڸ� �����ϰ� ������ �õ�(seed)�� �ʱ�ȭ �Ѵ�.
auto ud = std::uniform_int_distribution<>{ 1,6 };	//������ ����� ���ϴ� ����� ���� �� �ϳ��� ��ȯ�ϱ� ���� ��� ������ ������ �ϳ��� ����Ѵ�.


int main()
{
	for (auto i = 0; i < 20; ++i)
	{
		auto number = ud(mtgen);
		std::cout << number << std::endl;
	}

	auto mtgen2 = std::mt19937{};
	for(auto i = 0;i<10;++i)
		std::cout<<mtgen2()<<std::endl;
}