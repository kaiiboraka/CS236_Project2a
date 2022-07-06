//
// Created by Brandon on 6/23/2022.
//

#include "FSA_Rules.h"

void FSA_Rules::s0() // R
{
	if (EndOfFile())
		SError();

	else if (Match('R'))
	{
		Next();
		s1_u();
	}
	else
	{
		SError();
	}
}

void FSA_Rules::s1_u()
{
	if (EndOfFile())
		SError();

	else if (Match('u'))
	{
		Next();
		s2_l();
	}
	else
		SError(); // this calls the error state
}


void FSA_Rules::s2_l()
{
	if (EndOfFile())
		SError();

	else if (Match('l'))
	{
		Next();
		s3_e();
	}
	else
		SError(); // this calls the error state
}


void FSA_Rules::s3_e()
{
	if (EndOfFile())
		SError();

	else if (Match('e'))
	{
		Next();
		s4_s();
	}
	else
		SError(); // this calls the error state
}


void FSA_Rules::s4_s()
{
	if (EndOfFile())
		SError();

	else if (Match('s'))
	{
		Next();
		return;
	}
	else
		SError(); // this calls the error state
}