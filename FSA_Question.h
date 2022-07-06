#pragma once

#include "Automaton.h"

class FSA_Question : public Automaton
{
public:
	FSA_Question()
	{
		type = Q_MARK;
	}
};