#include <Windows.h>
#include <string>

enum TextVAligment
{
	Middle,Left
};

struct Control
{
	const int DefaultHeigh = 14;
	const int DefaultWidth = 80;

	TextVAligment valign = TextVAligment::Middle;
	TextVAligment halign = TextVAligment::Left;

	std::string text;
	
	Control(std::string const& t) :text(t) {}
	Control(std::string const& t, TextVAligment const& va, TextVAligment const& ha) :text(t), valign(va), halign(ha) {}
	


};