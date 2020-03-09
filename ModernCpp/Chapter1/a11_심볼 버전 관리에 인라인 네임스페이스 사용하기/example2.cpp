namespace modernlib
{
	namespace version_1
	{
		template<typename T>
		int test(T value) { return 1; }
	}

#ifndef LIB_VERSION_2
	using namespace version_1;
#endif

	namespace version_2
	{
		template<typename T>
		int test(T value) { return 2; }
	}

#ifdef LIB_VERSION_2
	using namespace version_2;
#endif
}