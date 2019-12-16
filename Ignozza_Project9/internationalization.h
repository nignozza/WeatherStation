#pragma once
#include<fstream>
#include<iostream>
using namespace std;
class ReadData {
	// fstream outptr;
public:

	ReadData(); // Default constructor
	void ReadEnglishContents(string, int);
	void ReadLatincontents(string, int);
};
