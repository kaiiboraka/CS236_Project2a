#pragma once

#include "Automaton.h"

class FSA_Queries : public Automaton
{
	void s0()/*Q*/ override;
	void s1_u();
	void s2_e();
	void s3_r();
	void s4_i();
	void s5_e();
	void s6_s();

public:
	FSA_Queries()
	{
		type = QUERIES;
	}
};