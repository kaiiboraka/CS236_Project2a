//
// Created by Brandon on 6/30/2022.
//

#ifndef LAB1_PARSER_H
#define LAB1_PARSER_H

#include "Token.h"

using namespace Tokens;

class Parser
{
	const unsigned int NEXT = 1;

	vector<Token> tokens;
	unsigned int currTokenIdx;
	unsigned int step;
	vector<TokenType> steps =
		{
			SCHEMES,
			FACTS,
			RULES,
			QUERIES,
			END_OF_FILE
		};

public:
	explicit Parser(const vector<Token>& tokens);

	[[nodiscard]] TokenType CurrTokenType();

	void AdvanceToken();

	void ThrowError();

	void Match(TokenType expectedType);

	void CheckForComments();

	void Run();

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

	void DatalogProgram();

	void Scheme();

	void IDList();

	void SchemeList();

	void Fact();

	void StringList();

	void FactList();

	void Rule();

	void HeadPredicate();

	void Predicate();

	void Parameter();

	void ParameterList();

	void PredicateList();

	void RuleList();

	void Query();

	void QueryList();

};


#endif //LAB1_PARSER_H
