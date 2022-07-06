#pragma once

#include "Automaton.h"

class FSA_Paren_Left : public Automaton
{
public:
	FSA_Paren_Left()
	{
		type = LEFT_PAREN;
	}
};