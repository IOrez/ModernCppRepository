#include <iostream>
#include <random>									//random헤더를 포함한다.

std::random_device rd{};							//의사난수엔진을 사용하기 위해 std::random_device 생성기를 사용한다.
auto mtgen = std::mt19937{ rd() };					//사용 가능한 엔진 중 하나를 사용해 숫자를 생성하고 임의의 시드(seed)로 초기화 한다.
auto ud = std::uniform_int_distribution<>{ 1,6 };	//엔진의 결과를 원하는 통계적 분포 중 하나로 변환하기 위해 사용 가능한 분포중 하나를 사용한다.


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