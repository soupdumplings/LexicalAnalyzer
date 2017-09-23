#pragma once

#include <iostream>
#include <string>
#include "FileReader.h"
#include "Parser.h"
#include "Table.h"
#include "TokensTypes.h"

using namespace std;

class LexicalAnalyzer
{
	private:
		Table tokens;
		FileReader reader;

		tokensType whatType(const string& token);
		bool isSeparator(const string& token);
		bool isEndOfSentense(const string& token);
		bool isPunctuationSymbol(const string& token);
		bool isWord(const string& token);
		bool isNumber(const string& token);
		bool isIndeficator(const string& token);
		bool isForeignWord(const string& token);
		bool isDate(const string& token);
		bool isPhoneNumber(const string& token);
		bool isUkrLetter(const char ch);
		LexicalAnalyzer& operator =(const LexicalAnalyzer&);
	public:
		LexicalAnalyzer(const string& fileName);
		~LexicalAnalyzer();
		void getAnalysis();
};
