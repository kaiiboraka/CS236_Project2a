#pragma once

#include "Automaton.h"

class FSA_Period : public Automaton
{
public:
	FSA_Period()
	{
		type = PERIOD;
	}
};