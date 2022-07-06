#pragma once
#include "Automaton.h"

class FSA_Comma : public Automaton
{
public:
	FSA_Comma()
	{
		type = COMMA;
	}
};