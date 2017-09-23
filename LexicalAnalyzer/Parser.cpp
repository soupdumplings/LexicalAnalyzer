#include "Parser.h"
Parser::Parser(const string& s):
_parsingString(s), _positionInString(0)
{}

Parser::~Parser()
{}

string Parser::getNextToken()
{
	string res;
	if (!isEndOfString())
	{
		if (isSymbol(_parsingString[_positionInString]))
		{
			// якщо це сиволи роздільники дати або телефону
			if (isDataSymbol())
			{
				res += _parsingString[_positionInString];
				++_positionInString;
			}
			//навпаки
			else 
			{
				res += _parsingString[_positionInString];
				++_positionInString;
				return res;
			}
		}
		while (!isEndOfString() && ( isDataSymbol() ||
			!isSymbol(_parsingString[_positionInString])) )
		{
			if (_parsingString[_positionInString] == 'і')
			{
				res += 'i';

			}
			else if (_parsingString[_positionInString] == 'І')
			{
				res += 'I';
			}
			else
			{
				res += _parsingString[_positionInString];
			}
			++_positionInString;
		}
	}
	return res;
}

bool Parser::isEndOfString()
{
	return _positionInString > _parsingString.length();
}

bool Parser::isSymbol(const char& ch)
{
	return !isLetter(ch) && ch != '-' && ch != '\'' && ch != '’' && !isNumber(ch)&&
		!(ch >= 'A' && ch <= 'Z') &&
		!(ch >= 'a' && ch <= 'z');
}

bool Parser::isLetter(const char& ch)
{
	return (ch >= 'А' && ch <= 'Я') || ch == 'І' || ch == 'Ї' || ch == 'Ґ' || ch == 'ґ'
		|| (ch >= 'а' && ch <= 'я') || ch == 'і' || ch == 'ї' || ch == 'є' || ch == 'Є';
}

bool Parser::isNumber(const char& ch)
{
	return (ch >= '0' && ch <= '9');
}

bool Parser::isDataSymbol()
{
	return (_positionInString > 0 && (_positionInString + 1) <= _parsingString.length()
		&& isNumber(_parsingString[_positionInString - 1]) && (isNumber(_parsingString[_positionInString + 1]) || _parsingString[_positionInString + 1]=='-')
		&& _parsingString[_positionInString] != ' ') || _parsingString[_positionInString] == '+' ||
		(_parsingString[_positionInString] == '(' && (_positionInString + 1) <= _parsingString.length()&& isNumber(_parsingString[_positionInString + 1]));
}