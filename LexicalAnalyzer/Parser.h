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
	public:
		Parser(const string&);
		~Parser();
		string getNextToken();
		bool isEndOfString();
};