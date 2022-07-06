#pragma once

#include "Automaton.h"

class FSA_EOF : public Automaton
{
	void s0() override;

public:
	FSA_EOF()
	{
		type = END_OF_FILE;
	}
};

void FSA_EOF::s0()
{
	if (EndOfFile())
	{
		numCharRead++;
		currCharIndex++;
		return;
	}
}
