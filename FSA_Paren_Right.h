#pragma once

#include "Automaton.h"

class FSA_Paren_Right : public Automaton
{
public:
	FSA_Paren_Right()
	{
		type = RIGHT_PAREN;
	}
};