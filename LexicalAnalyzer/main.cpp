#include "LexicalAnalyzer.h"
#include <locale>

int main()
{

	setlocale(LC_ALL, "Ukrainian");

	LexicalAnalyzer la("text.txt");
	la.getAnalysis();
}