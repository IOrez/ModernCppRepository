#include <iostream>
#include <string>

namespace
{
	void print(std::string message)
	{
		std::cout << "[file1]" << message << std::endl;
	}
}
void file1_run()
{
	print("run");
}

