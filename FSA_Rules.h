#pragma once

#include "Automaton.h"

class FSA_Rules : public Automaton
{
	void s0()/*R*/ override;
	void s1_u();
	void s2_l();
	void s3_e();
	void s4_s();

public:
	FSA_Rules()
	{
		type = RULES;
	}
};