#pragma once

#include "Automata.h"

class Lexer
{
	vector<Automaton*> automata;
	vector<string> lines;
	vector<Token> tokens;

	void InitializeAutomata()
	{
		// Priority List
		automata.push_back(new FSA_Comma());
		automata.push_back(new FSA_Period());
		automata.push_back(new FSA_Question());
		automata.push_back(new FSA_Paren_Left());
		automata.push_back(new FSA_Paren_Right());
		automata.push_back(new FSA_Colon());
		automata.push_back(new FSA_ColonDash());
		automata.push_back(new FSA_Multiply());
		automata.push_back(new FSA_Add());
		automata.push_back(new FSA_Schemes());
		automata.push_back(new FSA_Facts());
		automata.push_back(new FSA_Rules());
		automata.push_back(new FSA_Queries());
		automata.push_back(new FSA_ID());
		automata.push_back(new FSA_String());
		automata.push_back(new FSA_Comment());
		//Lowest Priority
		automata.push_back(new FSA_EOF());
		automata.push_back(new FSA_Undefined());
	}

public:

	[[nodiscard]] const vector<Token>& GetTokens() const
	{
		return tokens;
	}

	vector<Token> Run(const string& outsideInput)
	{
		InitializeAutomata();

		string reducedInput = outsideInput;
		unsigned int line = 1;
		while (!reducedInput.empty())
		{
			RunAutomata(reducedInput, line);
		}

		AddToken(Token(END_OF_FILE, Symbols.at(END_OF_FILE), line));

		return tokens;
	}

	static void TrimWhitespace(string& input, unsigned int& lineNum)
	{
		while (isspace(input.front()) && !input.empty())
		{
			if (input.front() == '\n')
			{
				lineNum++;
			}
			input = input.substr(1);
		}
	}

	void RunAutomata(string& input, unsigned int& lineNum)
	{
		Automaton* maxAutomaton = automata.at(0);
		unsigned int maxRead = 0;
		TrimWhitespace(input, lineNum);
		for (auto currentAutomaton : automata)
		{
			CompareResults(input, currentAutomaton, maxAutomaton, maxRead);
		}
		string substr = input.substr(0, maxRead);
		if (maxAutomaton->GetType() == END_OF_FILE)
		{
			return;
		}
		AddToken(Token(maxAutomaton->GetType(), substr, lineNum));
		lineNum += maxAutomaton->GetNewLines();

		input = input.substr(maxRead, input.size());

	}

	static void CompareResults(const string& input,
							   Automaton* currentAutomaton,
							   Automaton*& maxAutomaton,
							   unsigned int& maxRead)
	{
		string result;

		unsigned int read = currentAutomaton->Run(input);
		//read == number of actual character symbols gone through,
		//automatically prioritizing longer FSAs more than shorter ones
		if (read > maxRead)
		{
			maxRead = read;
			maxAutomaton = currentAutomaton;
		}
	}

	void AddToken(const Token& currToken)
	{
		tokens.push_back(currToken);
	}

	static void PrintToken(ostream& os, Token& currToken)
	{
		os << currToken.ToString() << endl;
	}
};

