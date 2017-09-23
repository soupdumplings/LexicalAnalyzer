#pragma once
#include <string>
#include <iostream>
using namespace std;

class Parser
{
	private:
		string _parsingString;
		size_t _positionInString;
		Parser& operator =(const Parser&);
		Parser(const Parser& reader);
		bool isDataSymbol();
		bool isSymbol(const char& ch);
		bool isLetter(const char& ch);
		bool isNumber(const char& ch);
	public:
		Parser(const string&);
		~Parser();
		string getNextToken();
		bool isEndOfString();
};