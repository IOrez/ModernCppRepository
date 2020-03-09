#include <iostream>

struct handle_t
{
	explicit handle_t(int const h) :handle(h) {}
	explicit operator bool()const { return handle != 0; }
private:
	int handle;
};

struct foo
{
	foo() 
	{
		std::cout << "foo" << std::endl;
	}
	foo(int const a)
	{
		std::cout << "foo(a)" << std::endl;
	}
	foo(int const a, double const b)
	{
		std::cout << "foo(a,b)" << std::endl;
	}

	operator bool()const { return true; }
};

void bar(foo const f)
{

}

int main()
{
	foo f1;				//foo
	foo f2;				//foo

	foo f3(1);			//foo(a)
	foo f4 = 1;			//foo(a)
	foo f5{ 1 };		//foo(a)
	foo f6 = { 1 };		//foo(a)

	foo f7(1, 2.0);		//foo(a,b)
	foo f8{ 1,2.0 };	//foo(a,b)
	foo f9 = { 1,2.0 };	//foo(a,b)

	bar({});			//foo
	bar(1);				//foo(a)
	bar({ 1,2.0 });		//foo(a,b);

	bool flag = f1;
	if (f2) {}
	std::cout << f3 + f4 << std::endl;
	if (f5 == f6) {}

}