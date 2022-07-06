#pragma once

#include "Helper.h"

namespace Tokens
{
	enum TokenType
	{
		COMMA,
		PERIOD,
		Q_MARK,
		LEFT_PAREN,
		RIGHT_PAREN,
		COLON,
		COLON_DASH,
		MULTIPLY,
		ADD,
		SCHEMES,
		FACTS,
		RULES,
		QUERIES,
		ID,
		STRING,
		COMMENT,
		UNDEFINED,
		END_OF_FILE,
		TYPE_COUNT
	};

	static const string TokenNames[] =
	{
		"COMMA",
		"PERIOD",
		"Q_MARK",
		"LEFT_PAREN",
		"RIGHT_PAREN",
		"COLON",
		"COLON_DASH",
		"MULTIPLY",
		"ADD",
		"SCHEMES",
		"FACTS",
		"RULES",
		"QUERIES",
		"ID",
		"STRING",
		"COMMENT",
		"UNDEFINED",
		"EOF",
		"TYPE_COUNT"
	};

	static const map<TokenType, string> Symbols =
	{
		{COMMA,       ","},
		{PERIOD,      "."},
		{Q_MARK,      "?"},
		{LEFT_PAREN,  "("},
		{RIGHT_PAREN, ")"},
		{COLON,       ":"},
		{COLON_DASH,  ":-"},
		{MULTIPLY,    "*"},
		{ADD,         "+"},
		{SCHEMES,     Helper::ToCapitalized(TokenNames[SCHEMES])},
		{FACTS,       Helper::ToCapitalized(TokenNames[FACTS])},
		{RULES,       Helper::ToCapitalized(TokenNames[RULES])},
		{QUERIES,     Helper::ToCapitalized(TokenNames[QUERIES])},
		{ID,          TokenNames[ID]},
		{STRING,      "'"},
		{COMMENT,     "#"},
		{UNDEFINED,   TokenNames[UNDEFINED]},
		{END_OF_FILE, ""},
		{TYPE_COUNT,  ""},
	};

	class Token
	{
		TokenType type;
		string value;
		unsigned int line;
	public:

		Token(const TokenType& newType, const string& newValue, const unsigned int& newLine)
				: type(newType), value(newValue), line(newLine)
		{}
		const string& GetValue() const
		{
			return value;
		}

		TokenType GetType() const
		{
			return type;
		}

		string ToString() const
		{
			ostringstream oss;
			oss << "(" << TokenNames[type] << "," << "\"" << value << "\"" << "," << line << ")";
			return oss.str();
		}
	};

}