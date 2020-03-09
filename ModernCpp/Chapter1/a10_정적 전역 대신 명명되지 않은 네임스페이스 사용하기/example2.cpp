#include <iostream>
#include <string>

namespace 
{
	void print(std::string message)
	{
		std::cout << "[file2]"<<std::endl;
	}
}

void file2_run()
{
	print("run");
}


template<int const& Size>
class test {};

static int Size1 = 10;

namespace
{
	int Size2 = 10;
}

test<Size1> t1;				//컴파일 오류:: 템플릿 인수는 내부링크를 가진 이름이 될 수 없기 때문에 정적 변수를 사용할 수 없다.
test<Size2> t2;				//성공!!	외부연결을 가진다.