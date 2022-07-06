//
// Created by Brandon on 6/23/2022.
//

#include "FSA_Undefined.h"

void FSA_Undefined::s0()
{
	if (EndOfFile())
		SError();

	else
		Next();
}
