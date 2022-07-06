#pragma once

#include "Automaton.h"

class FSA_Multiply : public Automaton
{
public:
	FSA_Multiply()
	{
		type = MULTIPLY;
	}
};