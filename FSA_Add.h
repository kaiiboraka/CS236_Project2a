#pragma once

#include "Automaton.h"

class FSA_Add : public Automaton
{
public:
	FSA_Add()
	{
		type = ADD;
	}
};