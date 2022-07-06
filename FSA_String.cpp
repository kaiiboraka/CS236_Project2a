#include "FSA_String.h"

void FSA_String::s0()
{
	if (EndOfFile())
		SError();

	else if (Match(quote))
	{
		Next();
		s1_string();
	}
	else
	{
		SError();
	}
}

void FSA_String::s1_string()
{
	if (EndOfFile())
	{
		type = UNDEFINED;
		return;
	}

	else if (!Match(quote))
	{
		Next();
		s1_string();
	}
	else if (Match(quote))
	{
		Next();
		s2_quote();
	}
	else
		SError(); // this calls the error state
}

void FSA_String::s2_quote()
{
	if (EndOfFile())
		SError();

	else if (Match(quote))
	{
		Next();
		s1_string();
	}
	else if (!Match(quote))
	{
		return;
	}
	else
		SError(); // this calls the error state
}
