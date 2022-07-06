#include "FSA_Comment.h"

void FSA_Comment::s0()
{
	if (EndOfFile())
		SError();

	else if (Match(comment))
	{
		Next();
		s1();
	}
	else
	{
		SError();
	}
}

void FSA_Comment::s1()
{
	if (EndOfFile())
	{
		SError();
	}
	else if (Match(block))
	{
		Next();
		s3_block();
	}
	else if (Match('\n') || Match('\r'))
	{
		return; // this represents accepting the input
	}
	else if (!Match('\n') && !Match('\r'))
	{
		Next();
		s2_line(); // this represents accepting the input
	}
	else
		SError(); // this calls the error state
}

void FSA_Comment::s2_line()
{
	if (EndOfFile())
	{
		return; // accept
	}
	else if (Match('\n') || Match('\r'))
	{
		return; // this represents accepting the input
	}
	else if (!Match('\n') && !Match('\r'))
	{
		Next();
		s2_line();
	}
	else
		return; //accept
}


void FSA_Comment::s3_block()
{
	if (EndOfFile())
	{
		type = UNDEFINED;
		return; // accept
	}
	else if (Match(block))
	{
		Next();
		s4_end();
	}
	else if (!Match(block))
	{
		Next();
		s3_block();
	}
	else
		return; //accept
}

void FSA_Comment::s4_end()
{
	if (EndOfFile())
	{
		type = UNDEFINED;
		return; // accept
	}
	else if (Match(comment))
	{
		Next();
		return;
	}
	else
	{
		Next();
		s3_block();
	}
}