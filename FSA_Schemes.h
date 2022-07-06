#pragma once

#include "Automaton.h"

class FSA_Schemes : public Automaton
{
	void s0()/*S*/ override;
	void s1_c();
	void s2_h();
	void s3_e();
	void s4_m();
	void s5_e();
	void s6_s();

public:
	FSA_Schemes()
	{
		type = SCHEMES;
	}
};