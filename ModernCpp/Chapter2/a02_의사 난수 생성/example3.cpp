#include <iostream>
#include <random>
#include <functional>
#include <map>
#include <iomanip>
void generate_and_print(std::function<int(void)>gen, int const iterations = 10000)
{
	//숫자와 이 숫자의 반복을 저장하기 위한 맵
	auto data = std::map<int, int>{};

	//난수 생성
	for (auto n = 0; n < iterations; ++n)
		++data[gen()];

	//가장 반복되는 요소를 찾음
	auto max = std::max_element(std::begin(data), std::end(data), [](auto kbp1, auto kbp2) {
		return kbp1.second < kbp2.second;
	});

	//막대 모양 출력
	for (auto i = max->second / 200; i > 0; --i)
	{
		for (auto kvp : data)
		{
			std::cout
				<< std::fixed << std::setprecision(1) << std::setw(3) << (kvp.second / 200 >= i ? 'o' : ' ');
		}
		std::cout << std::endl;
	}


	//숫자출력
	for (auto kvp : data)
	{
		std::cout
			<< std::fixed << std::setprecision(1) << std::setw(3) << kvp.first;
	}
	std::cout << std::endl;
}

int main()
{
	std::random_device rd{};
	auto mtgen = std::mt19937{ rd() };
	auto ud = std::uniform_int_distribution<>{ 1,6 };
	generate_and_print([&mtgen, &ud]() {return ud(mtgen); });

	std::cout << "\n\n\n\n";

	auto nd = std::normal_distribution<>{ 0,1 };
	generate_and_print([&mtgen, &nd]() {return static_cast<int>(std::round(nd(mtgen))); });
	return 0;
}