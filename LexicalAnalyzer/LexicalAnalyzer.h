#pragma once

#include <string>
#include "FileReader.h"
#include "Parser.h"
#include "Table.h"
#include "TokensTypes.h"

class LexicalAnalyzer
{
	private:
		Table* tokens;
		FileReader* reader;
		Parser* parser;
		tokensType whatType(string token);
		LexicalAnalyzer& operator =(const LexicalAnalyzer&);
	public:
		LexicalAnalyzer(string fileName);
		~LexicalAnalyzer();
		void getAnalysis();
};
