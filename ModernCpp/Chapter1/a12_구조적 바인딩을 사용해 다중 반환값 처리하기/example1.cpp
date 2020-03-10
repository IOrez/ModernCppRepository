#include <iostream>
#include <tuple>
#include <string>

std::tuple<int, std::string, double> find()				//반환타입에 std:tuple을 사용한다
{
	return std::make_tuple(1, "marius", 1234.5);
}

int main()
{
	auto [id, name, score] = find();					//구조적 바인딩을 사용해 튜플의 값을 명명된 객체로 압출 해제한다.

	if (auto [id, name, score] = find();score>100)		//분해(decomposition)선언을 사용해 if문 또는 switch문 내에서 반환된 값을 변수에 바인딩한다.
	{
		std::cout << name << std::endl;
	}


}