#include "FileReader.h"

FileReader::FileReader(const string& fileName):
	buffer(), currentStream(fileName)
{
	setlocale(LC_ALL, "Ukrainian");
}

FileReader::~FileReader()
{
	currentStream.close();
}

string& FileReader::readLine()
{
	if (!endOfFile()) 
	{
		setlocale(LC_ALL, "Ukrainian");
		getline(currentStream, buffer);
		return buffer;
	}
	else
		return string();
}

bool FileReader::endOfFile()
{
	return currentStream.eof();
}