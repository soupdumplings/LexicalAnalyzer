#pragma once
#include <string>
#include <iostream>
#include <fstream> 

using namespace std;

class FileReader
{
	private:
		ifstream currentStream;
		string buffer;
		FileReader& operator =(const FileReader&);
		FileReader(const FileReader& reader);
	public:
		explicit FileReader(const string& fileName);
		~FileReader();
		string& readLine();
		bool endOfFile();
};
