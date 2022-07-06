#include "Lexer.h"
#include "Parser.h"
#include <fstream>

void TryParse(const vector<Token>& tokens, ostream& os);

string ReadFileIntoString(const string& path);

int main(int argc, char* argv[])
{
	const string cmake_path = "../input.txt";
	Lexer lexer;
	string input;
	if (argc <= 1)
	{
		try
		{
			input = ReadFileIntoString(cmake_path);
		}
		catch (exception& e){}
	}
	else
	{
		ifstream ifs(argv[1]);
		if (!ifs.is_open())
		{
			ifs.open("./Project2aPassOffCases/2-80/" + string(argv[1]));
		}
		string line;
		while (getline(ifs, line))
		{
			input += line + '\n';
		}
	}

	vector<Token> tokens = lexer.Run(input);

	TryParse(tokens, cout);

	return 0;
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

string ReadFileIntoString(const string& path)
{
	ifstream input_file(path);
	stringstream buffer;
	if (!input_file)
	{
		cerr << "Could not open the file - '"
			 << path << "'" << endl;
		exit(EXIT_FAILURE);
	}
	buffer << input_file.rdbuf();
	return buffer.str();
}
