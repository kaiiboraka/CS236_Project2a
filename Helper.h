#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class Helper
{
public:
	static string ToCapitalized(const string& input)
	{
		char upperFirst = char(toupper(input.at(0)));
		string lowerRest = input.substr(1, input.size());
		transform(lowerRest.begin(), lowerRest.end(), lowerRest.begin(), ::tolower);
		return string() + upperFirst + lowerRest;
	}

	template<class T>
	static void Test(const string& message, T const& expected, T const& observed)
	{
		try
		{
			cout << message << endl;
			cout << "Expected: >" << expected;
			cout << "< Observed: " << observed << endl;

			if (expected == observed)
			{
				cout << "Passed ✅" << endl;
			}
			else
			{
				cerr << "Failed ❌" << endl;
				throw invalid_argument(message);
			}
		}
		catch (exception& e)
		{
			cerr << e.what() << endl;
		}
	}
};

