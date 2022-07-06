
#include "FSA_Schemes.h"

void FSA_Schemes::s0() // S
{
	if (EndOfFile())
		SError();

	else if (Match('S'))
	{
		Next();
		s1_c();
	}
	else
	{
		SError();
	}
}

void FSA_Schemes::s1_c()
{
	if (EndOfFile())
		SError();

	else if (Match('c'))
	{
		Next();
		s2_h();
	}
	else
		SError(); // this calls the error state
}


void FSA_Schemes::s2_h()
{
	if (EndOfFile())
		SError();

	else if (Match('h'))
	{
		Next();
		s3_e();
	}
	else
		SError(); // this calls the error state
}


void FSA_Schemes::s3_e()
{
	if (EndOfFile())
		SError();

	else if (Match('e'))
	{
		Next();
		s4_m();
	}
	else
		SError(); // this calls the error state
}


void FSA_Schemes::s4_m()
{
	if (EndOfFile())
		SError();

	else if (Match('m'))
	{
		Next();
		s5_e();
	}
	else
		SError(); // this calls the error state
}

void FSA_Schemes::s5_e()
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

void FSA_Schemes::s6_s()
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
