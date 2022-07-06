#pragma once
#include "Token.h"
using namespace Tokens;

class Automaton
{
protected:
	// This tracks where in the input we are
	unsigned int currCharIndex = 0;

	// This tracks the number of newLines we have read
	unsigned int newLinesRead = 0;

	TokenType type = UNDEFINED;
	// This tracks the total number of characters consumed
	// This is different from currCharIndex to let you "peek" at the Next input without consuming it
	unsigned int numCharRead = 0;
	string input;

	// All children of this class must define this function
	virtual void s0()
	{
		if (EndOfFile())
			SError();

		else if ( Match(  Symbols.at(type).front()  ) )
		{
			Next();
			return;
		}
		else
		{
			SError();
		}
	}
	// Helper functions
	void Next()
	{
		if (Current() == '\n')
			newLinesRead++;
		numCharRead++;
		currCharIndex++;
	}

	char Peek()
	{
		if (EndOfFile())
			throw out_of_range(TokenNames[type] + " PEEK: Tried to read past the file, does your automaton state check for it as a transition?");
		return input.at(currCharIndex + 1);
	}

	char Current()
	{
		if (EndOfFile())
			throw out_of_range(TokenNames[type] + " CURRENT: Tried to read past the file, does your automaton state check for it as a transition?");
		return input.at(currCharIndex);
	}

	bool Match(char c)
	{
		if (EndOfFile())
			throw out_of_range(TokenNames[type] + " MATCH: Tried to read past the file, does your automaton state check for it as a transition?");
		return (Current() == c);
	}

	bool MatchNext(char c)
	{
		if (EndOfFile())
			throw out_of_range("Tried to read past the file, does your automaton state check for it as a transition?");
		return (Peek() == c);
	}

	// Call this function to check if you have reached the end of file
	bool EndOfFile()
	{
		return (currCharIndex >= input.size());
	}

	// This is the error state call it when the token is invalid
	void SError()
	{
		numCharRead = 0;
	}

public:
	Automaton()	= default;

	unsigned int Run(const string& newInput)
	{
		input = newInput;
		currCharIndex = 0;
		newLinesRead = 0;
		numCharRead = 0;
		s0();
		return numCharRead;
	}

	unsigned int GetNewLines() const
	{
		return newLinesRead;
	}

	TokenType GetType()
	{
		return type;
	}

};