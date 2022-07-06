#include "Datalog.h"

int main(int argc, char* argv[])
{
	string input = (argc <= 1) ?
				   TryReadFile(FILE_PATH) :
				   TryReadArgs(argv[1]);

	auto tokens = LexTokens(input);

	TryParse(tokens, cout);

	return 0;
}