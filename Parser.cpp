#include "Parser.h"

Parser::Parser(const vector<Token>& tokens)
	: tokens(tokens), currTokenIdx(0), step(0)
{

}

TokenType Parser::CurrTokenType()
{
	if (currTokenIdx >= tokens.size()) return UNDEFINED;
	return tokens.at(currTokenIdx).GetType();
}

void Parser::AdvanceToken()
{
	currTokenIdx++;
}

void Parser::ThrowError()
{
	if (currTokenIdx >= tokens.size()) throw tokens.at(tokens.size() - 1);
	throw tokens.at(currTokenIdx);
}

void Parser::Match(TokenType expectedType)
{
	if (CurrTokenType() == expectedType)
	{
		AdvanceToken();
	}
	else
	{
		ThrowError();
	}
}

void Parser::CheckForComments()
{
	while (CurrTokenType() == COMMENT)
	{
		AdvanceToken();
	}
}

void Parser::Run()
{
	DatalogProgram();
}

void Parser::DatalogProgram()
{
	// datalogProgram -> SCHEMES COLON scheme schemeList FACTS COLON factList
	//					 RULES COLON ruleList QUERIES COLON query queryList EOF
	step = 0;

	CheckForComments();
	Match(SCHEMES);
	Match(COLON);
	Scheme();
	SchemeList();
	step++;

	Match(FACTS);
	Match(COLON);
	FactList();
	step++;

	Match(RULES);
	Match(COLON);
	RuleList();
	step++;

	Match(QUERIES);
	Match(COLON);
	Query();
	QueryList();
	step++;

	Match(END_OF_FILE);
}

void Parser::Scheme()
{
	// scheme -> ID LEFT_PAREN ID idList RIGHT_PAREN
	CheckForComments();

	Match(ID);
	Match(LEFT_PAREN);
	Match(ID);
	IDList();
	Match(RIGHT_PAREN);
}

void Parser::IDList()
{
	//	idList  	-> 	COMMA ID idList | lambda
	CheckForComments();
	if (CurrTokenType() != COMMA) return;

	Match(COMMA);
	Match(ID);
	IDList();
	// else do nothing, lambda case
}

void Parser::SchemeList()
{
	// schemeList -> scheme schemeList | lambda
	CheckForComments();
	if (CurrTokenType() == steps.at(NEXT + step)) return;

	Scheme();
	SchemeList();
}

void Parser::Fact()
{
	// fact -> ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
	CheckForComments();

	Match(ID);
	Match(LEFT_PAREN);
	Match(STRING);
	StringList();
	Match(RIGHT_PAREN);
	Match(PERIOD);
}

void Parser::StringList()
{
	//	stringList	-> 	COMMA STRING stringList | lambda
	CheckForComments();
	if (CurrTokenType() != COMMA) return;

	Match(COMMA);
	Match(STRING);
	StringList();
	// else do nothing, lambda case
}

void Parser::FactList()
{
	// factList -> fact factList | lambda
	CheckForComments();
	if (CurrTokenType() == steps.at(NEXT + step))
	{ return; }

	Fact();
	FactList();
}

void Parser::Rule()
{
	// rule -> headPredicate COLON_DASH predicate predicateList PERIOD
	CheckForComments();

	HeadPredicate();
	Match(COLON_DASH);
	Predicate();
	PredicateList();
	Match(PERIOD);
}

void Parser::HeadPredicate()
{
	//	headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
	CheckForComments();
	Match(ID);
	Match(LEFT_PAREN);
	Match(ID);
	IDList();
	Match(RIGHT_PAREN);
}

void Parser::Predicate()
{
	//	predicate		->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
	CheckForComments();
	Match(ID);
	Match(LEFT_PAREN);
	Parameter();
	ParameterList();
	Match(RIGHT_PAREN);
}

void Parser::Parameter()
{
	//	parameter	->	STRING | ID
	CheckForComments();
	switch (CurrTokenType())
	{
		case STRING: Match(STRING);
			return;
		case ID: Match(ID);
			return;
		default: return;
	}
}

void Parser::ParameterList()
{
	//	parameterList	-> 	COMMA parameter parameterList | lambda
	CheckForComments();
	if (CurrTokenType() != COMMA) return;

	Match(COMMA);
	Parameter();
	ParameterList();

	// else do nothing, lambda case
}

void Parser::PredicateList()
{
	//	predicateList	->	COMMA predicate predicateList | lambda
	CheckForComments();
	if (CurrTokenType() != COMMA) return;

	Match(COMMA);
	Predicate();
	PredicateList();
	// else do nothing, lambda case
}

void Parser::RuleList()
{
	// ruleList -> rule ruleList | lambda
	CheckForComments();
	if (CurrTokenType() == steps.at(NEXT + step))
	{ return; }

	Rule();
	RuleList();
}

void Parser::Query()
{
	//	query	    ->  predicate Q_MARK
	CheckForComments();

	Predicate();
	Match(Q_MARK);
}

void Parser::QueryList()
{
	// queryList -> query queryList | lambda
	CheckForComments();
	if (CurrTokenType() == steps.at(NEXT + step))
	{ return; }

	Query();
	QueryList();
}
