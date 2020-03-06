enum class Status {Unknown, Created, Connected};
Status s = Status::Created;



//enum Status {UnKnown,Created,Connected};
//enum Codes {OK,Failure,Unknown};
//auto status = Status::Created;

enum class Codes : unsigned int;

void print_code(Codes const code) {}

enum class Codes :unsigned int
{
	OK = 0,
	Failure = 1,
	UnKnown = 0xFFFF0000U
};

Codes c1 = Codes::OK;
//int c2 = Codes::Failure; ¿À·ù
int c3 = static_cast<int>(Codes::Failure);