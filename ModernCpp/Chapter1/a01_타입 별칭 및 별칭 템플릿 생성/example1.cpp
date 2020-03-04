#include <vector>
#include <string>

using byte = unsigned char;
using pbyte = unsigned char*;
using array_t = int[10];
using fn = void(byte, double);

void func(byte b, double d){/*...*/}
byte b{ 42 };
pbyte pb = new byte[10]{ 0 };
array_t a{ 0,1,2,3,4,5,6,7,8,9 };
fn* f = func;

template <class T>
class custom_allocator{/*...*/ };

template<typename T>
using vec_t = std::vector<T, custom_allocator<T>>;


vec_t<int> vi;
vec_t<std::string> vs;