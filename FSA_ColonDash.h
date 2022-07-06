#pragma once

#include "Automaton.h"

class FSA_ColonDash : public Automaton
{
	void s0() override;
	void s1();

public:
	FSA_ColonDash()
	{
		type = COLON_DASH;
	}
};