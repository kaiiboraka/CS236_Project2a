#pragma once

#include "Automaton.h"

class FSA_Comment : public Automaton
{
	char comment;
	char block;

	void s0() override;
	void s1(); // #
	void s2_line(); // line comment
	void s3_block(); // block comment
	void s4_end();

public:
	FSA_Comment()
	{
		type = COMMENT;
		comment = Symbols.at(type).front();
		block = '|';
	}
};