#include <iostream>
#include <initializer_list>

class foo
{
	int a_;
	int b_;
public:
	foo() :a_(0), b_(0) {}
	foo(int a, int b = 0) :a_(a), b_(b) {}
	foo(std::initializer_list<int> l) {}
};

foo f{ 1,2 }; //initializer_list<int> ȣǮ <- �����Ģ!!!!!!!!!!! ������ ���� ���� ȣ��ȴ�!!!

void func(int const a, int const b, int const c)
{
	std::cout << a << b << c << std::endl;
}

void func(std::initializer_list<int> const l)
{
	for (auto const& e : l)
		std::cout << e << std::endl;
}

func({ 1,2,3 });//�ι��� �����ε� ȣǮ