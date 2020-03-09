namespace modernlib
{
#ifndef LIB_VERSION_2
	inline namespace version_1
	{
		template<typename T>
		int test(T value) { return 1; }
	}
#endif

#ifdef LIB_VERSION_2
	inline namespace version_2
	{
		template<typename T>
		int test(T value) { return 2; }
	}
#endif
}