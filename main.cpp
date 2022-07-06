#include "Lexer.h"
#include "Parser.h"
#include <fstream>

void TryParse(const vector<Token>& tokens, ostream& os);

string TryReadFile(const string& path);

string TryReadArgs(const string& pass_path, const string& argv);

int main(int argc, char* argv[])
{
	const string cmake_path = "cmake-build-debug/input.txt";
	const string pass_path = "Project2aPassOffCases/2-80/";

	string input = (argc <= 1) ?
				   TryReadFile(cmake_path) :
				   TryReadArgs(pass_path, argv[1]);

	Lexer lexer;
	vector<Token> tokens = lexer.Run(input);

	TryParse(tokens, cout);

	return 0;
}

string TryReadArgs(const string& pass_path, const string& argv)
{
	ifstream ifs(argv);
	if (!ifs.is_open()) ifs.open(pass_path + argv);
	string line, output;
	while (getline(ifs, line)) output += line + '\n';
	return output;
}

string TryReadFile(const string& path)
{
	string output;
	try
	{
		output = Helper::ReadFileIntoString(path);
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}
	return output;
}

void TryParse(const vector<Token>& tokens, ostream& os)
{
	try
	{
		Parser parser = Parser(tokens);
		parser.Run();
		os << "Success!";
	}
	catch (Token& errorToken)
	{
		os << "Failure!" << endl << "  " << errorToken.ToString();
	}
}

