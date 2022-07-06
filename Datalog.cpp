#include "Datalog.h"

vector<Token> LexTokens(const string& input)
{
	Lexer lexer;
	return lexer.Run(input);
}

string TryReadFile(const string& path)
{
	try
	{
		return Helper::ReadFileIntoString(path);
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return NULL;
	}
}

string TryReadArgs(const string& argv)
{
	ifstream ifs(argv);
	if (!ifs.is_open()) ifs.open(ARGS_PATH + argv);
	string line, output;
	while (getline(ifs, line)) output += line + '\n';
	return output;
}

void TryParse(const vector<Token>& tokens, ostream& os)
{
	try
	{
		Parser parser = Parser(tokens);
		parser.Run();
		os << "Success!" << endl;
	}
	catch (Token& errorToken)
	{
		os << "Failure!" << endl << "  " << errorToken.ToString() << endl;
	}
}

