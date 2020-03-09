#define LIB_VERSION_2
#include <iostream>
#include "example2.cpp"

struct foo { int a; };

namespace modernlib
{
	namespace version_2
	{
		template<>
		int test(foo value) { return value.a; }
	}
}

using namespace std;
int main()
{
	cout<<modernlib::test(foo{ 12345 })<<endl;
}