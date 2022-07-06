#pragma once

#include "Automaton.h"

class FSA_Facts : public Automaton
{
	void s0() override;//F
	void s1_a();
	void s2_c();
	void s3_t();
	void s4_s();

public:
	FSA_Facts()
	{
		type = FACTS;
	}
};