#pragma once

#include "Automaton.h"

class FSA_EOF : public Automaton
{
	void s0() override
	{
		if (EndOfFile())
		{
			numCharRead++;
			currCharIndex++;
			return;
		}
	}

public:
	FSA_EOF()
	{
		type = END_OF_FILE;
	}
};