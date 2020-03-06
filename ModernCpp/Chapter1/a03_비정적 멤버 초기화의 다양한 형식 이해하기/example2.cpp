#include <iostream>
#include <string>
using namespace std;

struct foo
{
	foo()
	{
		cout << "default constructor" << std::endl;
	}

	foo(std::string const& text)
	{
		cout << "constructor '" << text << "'" << endl;
	}

	foo(foo const& other)
	{
		cout << "copy constructor" << endl;
	}

	foo(foo&& other)
	{
		cout << "mvoe constructor" << endl;
	}

	foo& operator=(foo const& other)
	{
		cout << "assignment" << endl; return *this;
	}

	foo& operator= (foo&& other)
	{
		cout << "move assignment" << endl; return *this;
	}

	~foo()
	{
		cout << "destructor" << endl;
	}

};

struct bar
{
	foo f;
	bar(foo const& value):f(value)
	{
		f = value;
	}
};

int main()
{
	foo f;
	bar b(f);
}