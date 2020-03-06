#include <string>

enum class TextFlow {LeftToRight,RightToLeft};
struct Control
{
	const int DefaultHeight = 20;
	const int DefaultWidth = 100;

	TextFlow textFlow = TextFlow::LeftToRight;
	std::string text;

	Control(std::string t) :text(t) {}
};

struct bar
{
	Control c{ "default value" };
	bar() :c{ "constructor initializer" } 
	{}
};