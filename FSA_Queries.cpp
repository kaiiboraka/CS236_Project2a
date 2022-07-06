//
// Created by Brandon on 6/23/2022.
//

#include "FSA_Queries.h"

void FSA_Queries::s0() // Q
{
	if (EndOfFile())
		SError();

	else if (Match('Q'))
	{
		Next();
		s1_u();
	}
	else
	{
		SError();
	}
}

void FSA_Queries::s1_u()
{
	if (EndOfFile())
		SError();

	else if (Match('u'))
	{
		Next();
		s2_e();
	}
	else
		SError(); // this calls the error state
}


void FSA_Queries::s2_e()
{
	if (EndOfFile())
		SError();

	else if (Match('e'))
	{
		Next();
		s3_r();
	}
	else
		SError(); // this calls the error state
}


void FSA_Queries::s3_r()
{
	if (EndOfFile())
		SError();

	else if (Match('r'))
	{
		Next();
		s4_i();
	}
	else
		SError(); // this calls the error state
}


void FSA_Queries::s4_i()
{
	if (EndOfFile())
		SError();

	else if (Match('i'))
	{
		Next();
		s5_e();
	}
	else
		SError(); // this calls the error state
}

void FSA_Queries::s5_e()
{
	if (EndOfFile())
		SError();

	else if (Match('e'))
	{
		Next();
		s6_s();
	}
	else
		SError(); // this calls the error state
}

void FSA_Queries::s6_s()
{
	if (EndOfFile())
		SError();

	else if (Match('s'))
	{
		Next();
		return; // this represents accepting the input
	}
	else
		SError(); // this calls the error state
}
