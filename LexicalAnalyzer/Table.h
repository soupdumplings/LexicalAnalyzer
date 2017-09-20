#pragma once
#include <string>
#include <map>
#include <list>
#include "TokensTypes.h"

using namespace std;

class Table
{
	private:
		map <string, tokensType> tokens;
		Table& operator =(const Table&);
	public:
		Table();
		Table(const string&, const tokensType&);
		Table(const Table&);
		~Table();
		Table& add(const string&, const tokensType&);
		list<string> getByTokenType(const tokensType&) const;
		tokensType& getType(const string&) const;
};