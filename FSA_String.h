#pragma once

#include "Automaton.h"

class FSA_String : public Automaton
{
	char quote;

	void s0() override;
	void s1_string();
	void s2_quote();

public:
	FSA_String()
	{
		type = STRING;
		quote = Symbols.at(type).front();
	}
};