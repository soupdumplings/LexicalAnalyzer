#include "Table.h"

Table::Table(){}

Table::Table(const string& s, const tokensType& type)
{
	tokens.insert(pair<string, tokensType>(s, type));
}

Table::Table(const Table& other)
{
	tokens = other.tokens;
}

Table::~Table() { }

Table& Table::add(const string& s, const tokensType& type) 
{
	tokens.insert(pair<string, tokensType>(s, type));
	return *this;
}

list<string> Table::getByTokenType(const tokensType& type) 
{
	list<string> res;
	for (map<string, tokensType>::iterator it = tokens.begin(); it != tokens.end(); ++it)
	{
		if (it->second == type) 
		{
			res.push_front(it->first);
		}
	}
	return res;
}

const tokensType& Table::getType(const string& s) const
{
	return tokens.at(s);
}

ostream& operator<<(ostream& os, Table& tab)
{
	for (auto elem : tab.tokens)
	{
		cout << elem.first << " " << tab.name[elem.second] << endl;
	}
	return os;
}