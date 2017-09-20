#pragma once
#include <string>
#include <iostream>
#include <fstream> 

using namespace std;

class FileReader
{
	private:
		FILE* _file;
		string buffer;
		FileReader& operator =(const FileReader&);
	public:
		explicit FileReader(string& fileName);
		explicit FileReader(FILE& file);
		FileReader(const FileReader& reader);
		~FileReader();
		string& readLine() const;
};
