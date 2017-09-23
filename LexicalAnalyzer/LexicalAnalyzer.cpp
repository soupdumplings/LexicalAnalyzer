#include "LexicalAnalyzer.h"
#include <regex>

LexicalAnalyzer::LexicalAnalyzer(const string& fileName) :
	reader(fileName), tokens()
{}

LexicalAnalyzer::~LexicalAnalyzer()
{}

void LexicalAnalyzer::getAnalysis()
{
	while (!reader.endOfFile())
	{
		string s = reader.readLine();
		Parser parser(s);
		while (!parser.isEndOfString())
		{
			string token = parser.getNextToken();
			tokens.add(token, whatType(token));
		}
	}
	cout << tokens << endl;
}

tokensType LexicalAnalyzer::whatType(const string& token)
{
	if (isSeparator(token))
	{
		return SEPARATOR;
	}
	else if (isEndOfSentense(token))
	{
		return ENDOFSENTENSE;
	}
	else if (isPunctuationSymbol(token))
	{
		return PUNCTUATIONSYMBOL;
	}
	else if (isWord(token))
	{
		return WORD;
	}
	else if (isIndeficator(token))
	{
		return INDEFICATOR;
	}
	else if (isForeignWord(token))
	{
		return FOREIGNWORD;
	}
	else if (isDate(token))
	{
		return DATE;
	}
	else if (isPhoneNumber(token))
	{
		return PHONENUMBER;
	}
	else if (isNumber(token))
	{
		return NUMBER;
	}
	else 
	{
		return ERROR;
	}
}

bool LexicalAnalyzer::isSeparator(const string& token)
{
	return token == " "|| token == "\t" || token == "\n";
}

bool LexicalAnalyzer::isEndOfSentense(const string& token)
{
	return (token == "?" || token == "." || token == "!");
}

bool LexicalAnalyzer::isPunctuationSymbol(const string& token)
{
	return (token == "," || token == "—" || token == ":" || token == ";"
			|| token == "\"" || token == ")" || token == "(");
}

bool LexicalAnalyzer::isWord(const string& token)
{
	bool res = isUkrLetter(token[0]);
	for (size_t i = 1; i < token.length() && res; ++i)
	{
		res =  isUkrLetter(token[i]) ||
			   token[i] == '-' || token[i] == '\'' || token[i] == '’';
	}
	return res;
}

bool LexicalAnalyzer::isNumber(const string& token)
{
	bool res = true;
	for (size_t i = 0; i < token.length() && res; ++i)
	{
		res = (token[i] >= '0' && token[i] <= '9');
	}
	return res;
}

bool LexicalAnalyzer::isIndeficator(const string& token)
{
	bool res = isUkrLetter(token[0]);
	bool endLetters = false;
	for (size_t i = 1; i < token.length() && res; ++i)
	{
		if (endLetters)
		{
			res = (token[i] >= '0' && token[i] <= '9');
		}
		else
		{
			res = isUkrLetter(token[i]);
			if (!res && (token[i] >= '0' && token[i] <= '9'))
			{
				endLetters = true;
				res = true;
			}
		}
	}
	return res;
}

bool LexicalAnalyzer::isForeignWord(const string& token)
{
	bool res = (token[0] >= 'A' && token[0] <= 'Z') ||
		(token[0] >= 'a' && token[0] <= 'z');

	for (size_t i = 1; i < token.length() && res; ++i)
	{
		res = (token[i] >= 'A' && token[i] <= 'Z') ||
			(token[i] >= 'a' && token[i] <= 'z') ||
			token[i] == '-' || token[i] == '\'';
	}
	return res;
}

bool LexicalAnalyzer::isDate(const string& token)
{
	regex data("(0*[1-9]|[12][0-9]|3[01])[- /.](0*[1-9]|1[012])[- /.]([0-9]*[0-9])*[0-9]*[0-9]");
	regex data1("([0-9]*[0-9])*[0-9]*[0-9][- /.]((0*[1-9]|1[012])[- /.](0*[1-9]|[12][0-9]|3[01]))");
	return regex_match(token, data) || regex_match(token, data1);
}

bool LexicalAnalyzer::isPhoneNumber(const string& token)
{
	regex phoneSta("[0-9][0-9]-[0-9][0-9]-[0-9][0-9][0-9]*");
	regex phoneSta2("[(]*[0-9][0-9][0-9]*[)]*-*[0-9][0-9][0-9]-*[0-9][0-9]-*[0-9][0-9]*");
	regex phoneMobil("[(]*([+][1-9][(]*[1-9])*[0-9][)]*[0-9][)]*[0-9][0-9][0-9]-*[0-9][0-9]-*[0-9][0-9][0-9]*");
	return regex_match(token, phoneSta) || regex_match(token, phoneSta2) || regex_match(token, phoneMobil);
}

bool LexicalAnalyzer::isUkrLetter(const char ch)
{
	return (ch >= 'À' && ch <= 'ß') || ch == 'I' || ch == '¯' || ch == '¥' || ch == '´'
		|| (ch >= 'à' && ch <= 'ÿ') || ch == 'i' || ch == '¿' || ch == 'º' || ch == 'ª';
}