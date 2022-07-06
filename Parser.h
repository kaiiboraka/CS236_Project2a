//
// Created by Brandon on 6/30/2022.
//

#ifndef LAB1_PARSER_H
#define LAB1_PARSER_H

#include "Token.h"

using namespace Tokens;

class Parser
{
	vector<Token> tokens;
	unsigned int currTokenIdx;
	const unsigned int NEXT = 1;
	vector<TokenType> steps =
			{
					SCHEMES,
					FACTS,
					RULES,
					QUERIES,
					END_OF_FILE
			};
	unsigned int step;

public:
	explicit Parser(const vector<Token>& tokens) : tokens(tokens), currTokenIdx(0), step(0)
	{};

	void AdvanceToken()
	{
		currTokenIdx++;
	}

	void ThrowError()
	{
		if (currTokenIdx >= tokens.size()) throw tokens.at(tokens.size() - 1);
		throw tokens.at(currTokenIdx);
	}

	[[nodiscard]] TokenType CurrTokenType()
	{
		if (currTokenIdx >= tokens.size()) return UNDEFINED;
		return tokens.at(currTokenIdx).GetType();
	}

	string CurrTokenString()
	{
		if (currTokenIdx >= tokens.size()) return TokenNames[UNDEFINED];
		return tokens.at(currTokenIdx).ToString();
	}

	string PrintTypeFromTokens(int offset = 0)
	{
		unsigned int idx = currTokenIdx + offset;
		if (idx >= tokens.size()) return TokenNames[END_OF_FILE];
		return to_string(idx) + ": " + TokenNames[tokens.at(idx).GetType()];
	}

	void Match(TokenType expectedType)
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

	void CheckForComments()
	{
		while (CurrTokenType() == COMMENT)
		{
			AdvanceToken();
		}
	}

	void Run()
	{
		DatalogProgram();
	}

//private:
	/*
	datalogProgram	->	SCHEMES COLON scheme schemeList FACTS COLON factList
	 					RULES COLON ruleList QUERIES COLON query queryList EOF

	schemeList		->	scheme schemeList | lambda
	factList		->	fact factList | lambda
	ruleList		->	rule ruleList | lambda
	queryList		->	query queryList | lambda

	scheme   		-> 	ID LEFT_PAREN ID idList RIGHT_PAREN
	fact    		->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
	rule    		->	headPredicate COLON_DASH predicate predicateList PERIOD
	query	        ->  predicate Q_MARK

	headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
	predicate		->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN

	predicateList	->	COMMA predicate predicateList | lambda
	parameterList	-> 	COMMA parameter parameterList | lambda
	stringList		-> 	COMMA STRING stringList | lambda
	idList  		-> 	COMMA ID idList | lambda
	parameter		->	STRING | ID
 	*/


	// datalogProgram -> SCHEMES COLON scheme schemeList FACTS COLON factList
	//					 RULES COLON ruleList QUERIES COLON query queryList EOF
	void DatalogProgram()
	{
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

	//	schemeList	->	scheme schemeList | lambda
	//	factList	->	fact factList | lambda
	//	ruleList	->	rule ruleList | lambda
	//	queryList	->	query queryList | lambda

	// schemeList -> scheme schemeList | lambda
	void SchemeList()
	{
		CheckForComments();
		if (CurrTokenType() == steps.at(NEXT + step)) return;

		Scheme();
		SchemeList();
	}

	// factList -> fact factList | lambda
	void FactList()
	{
		CheckForComments();
		if (CurrTokenType() == steps.at(NEXT + step))
		{ return; }

		Fact();
		FactList();
	}

	// ruleList -> rule ruleList | lambda
	void RuleList()
	{
		CheckForComments();
		if (CurrTokenType() == steps.at(NEXT + step))
		{ return; }

		Rule();
		RuleList();
	}

	// queryList -> query queryList | lambda
	void QueryList()
	{
		CheckForComments();
		if (CurrTokenType() == steps.at(NEXT + step))
		{ return; }

		Query();
		QueryList();
	}

	//	scheme   	-> 	ID LEFT_PAREN ID idList RIGHT_PAREN
	//	fact    	->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
	//	rule    	->	headPredicate COLON_DASH predicate predicateList PERIOD
	//	query	    ->  predicate Q_MARK

	// scheme -> ID LEFT_PAREN ID idList RIGHT_PAREN
	void Scheme()
	{
		CheckForComments();

		Match(ID);
		Match(LEFT_PAREN);
		Match(ID);
		IDList();
		Match(RIGHT_PAREN);
	}

	// fact -> ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
	void Fact()
	{
		CheckForComments();

		Match(ID);
		Match(LEFT_PAREN);
		Match(STRING);
		StringList();
		Match(RIGHT_PAREN);
		Match(PERIOD);
	}

	// rule -> headPredicate COLON_DASH predicate predicateList PERIOD
	void Rule()
	{
		CheckForComments();

		HeadPredicate();
		Match(COLON_DASH);
		Predicate();
		PredicateList();
		Match(PERIOD);
	}

	//	query	    ->  predicate Q_MARK
	void Query()
	{
		CheckForComments();

		Predicate();
		Match(Q_MARK);
	}


	//	headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
	//	predicate		->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN

	//	headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
	void HeadPredicate()
	{
		CheckForComments();
		Match(ID);
		Match(LEFT_PAREN);
		Match(ID);
		IDList();
		Match(RIGHT_PAREN);
	}

	//	predicate		->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
	void Predicate()
	{
		CheckForComments();

		Match(ID);
		Match(LEFT_PAREN);
		Parameter();
		ParameterList();
		Match(RIGHT_PAREN);
	}

	//	predicateList	->	COMMA predicate predicateList | lambda
	//	parameterList	-> 	COMMA parameter parameterList | lambda
	//	stringList	-> 	COMMA STRING stringList | lambda
	//	idList  	-> 	COMMA ID idList | lambda
	//	parameter	->	STRING | ID
	void PredicateList()
	{
		CheckForComments();
		if (CurrTokenType() != COMMA) return;

		Match(COMMA);
		Predicate();
		PredicateList();
		// else do nothing, lambda case
	}

	void ParameterList()
	{

		CheckForComments();
		if (CurrTokenType() != COMMA) return;

		Match(COMMA);
		Parameter();
		ParameterList();

		// else do nothing, lambda case
	}

	void Parameter()
	{
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

	void StringList()
	{
		CheckForComments();
		if (CurrTokenType() != COMMA) return;

		Match(COMMA);
		Match(STRING);
		StringList();
		// else do nothing, lambda case
	}

	void IDList()
	{
		CheckForComments();
		if (CurrTokenType() != COMMA) return;

		Match(COMMA);
		Match(ID);
		IDList();
		// else do nothing, lambda case
	}

};


#endif //LAB1_PARSER_H
