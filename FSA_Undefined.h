//
// Created by Brandon on 6/23/2022.
//

#ifndef LAB1_FSA_UNDEFINED_H
#define LAB1_FSA_UNDEFINED_H
#include "Automaton.h"

class FSA_Undefined : public Automaton
{
	void s0() override;

public:
	FSA_Undefined()
	{
		type = UNDEFINED;
	}
};


#endif //LAB1_FSA_UNDEFINED_H
