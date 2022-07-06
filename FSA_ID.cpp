//
// Created by Brandon on 6/23/2022.
//

#include "FSA_ID.h"

void FSA_ID::s0()
{
	if (EndOfFile())
		SError();

	else if (isalpha(Current()))
	{
		Next();
		s1();
	}
	else
		SError();
}

void FSA_ID::s1()
{
	if (EndOfFile())
		SError();

	else if (isalnum(Current()))
	{
		Next();
		s1();
	}
	else
		return; //accept
}
