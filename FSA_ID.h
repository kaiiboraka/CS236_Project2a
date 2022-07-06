#pragma once

#include "Automaton.h"
// need these for isalnum and isalpha
#include <cstdio>
#include <cctype>

class FSA_ID : public Automaton
{
	void s0() override;
	void s1();

public:
	FSA_ID()
	{
		type = ID; // set the type
	}
};

