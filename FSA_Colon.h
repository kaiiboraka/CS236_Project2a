#pragma once

#include "Automaton.h"

class FSA_Colon : public Automaton
{
public:
	FSA_Colon()
	{
		type = COLON;
	}
};