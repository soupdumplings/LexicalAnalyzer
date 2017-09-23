#pragma once
#include <string>
#include <map>
#include <list>
#include <iostream>
#include "TokensTypes.h"

using namespace std;

class Table
{
	private:
		char *name[10] =
		{
			"Indificator",
			"Word",
			"Foreign word",
			"Number",
			"Date",
			"Phone number",
			"Separator",
			"Punctuatin symbol",
			"End of sentense",
			"Error token"
		};
		map <string, tokensType> tokens;
		Table& operator =(const Table&);
	public:
		Table();
		Table(const string&, const tokensType&);
		Table(const Table&);
		~Table();
		Table& add(const string&, const tokensType&);
		list<string> getByTokenType(const tokensType&);
		const tokensType& getType(const string&) const;
		friend ostream& operator<<(ostream&, Table&);
};
