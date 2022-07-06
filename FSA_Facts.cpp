#include "FSA_Facts.h"

void FSA_Facts::s0()
{
	if (EndOfFile())
		SError();

	else if (Match('F'))
	{
		Next();
		s1_a();
	}
	else
	{
		SError();
	}
}

void FSA_Facts::s1_a()
{
	if (EndOfFile())
		SError();

	else if (Match('a'))
	{
		Next();
		s2_c();
	}
	else
		SError(); // this calls the error state
}


void FSA_Facts::s2_c()
{
	if (EndOfFile())
		SError();

	else if (Match('c'))
	{
		Next();
		s3_t();
	}
	else
		SError(); // this calls the error state
}


void FSA_Facts::s3_t()
{
	if (EndOfFile())
		SError();

	else if (Match('t'))
	{
		Next();
		s4_s();
	}
	else
		SError(); // this calls the error state
}


void FSA_Facts::s4_s()
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
