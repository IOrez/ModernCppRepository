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

test<Size1> t1;				//������ ����:: ���ø� �μ��� ���θ�ũ�� ���� �̸��� �� �� ���� ������ ���� ������ ����� �� ����.
test<Size2> t2;				//����!!	�ܺο����� ������.