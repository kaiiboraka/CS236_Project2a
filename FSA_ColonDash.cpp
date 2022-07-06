//
// Created by Brandon on 6/23/2022.
//

#include "FSA_ColonDash.h"

void FSA_ColonDash::s0()
{
	if (EndOfFile())
		SError();

	else if (Match(':'))
	{
		Next();
		s1();
	}
	else
	{
		SError();
	}
}

void FSA_ColonDash::s1()
{
	if (EndOfFile())
	{
		SError();
	}
	else if (Match('-'))
	{
		Next();
		return; // this represents accepting the input
	}
	else
		SError(); // this calls the error state
}
