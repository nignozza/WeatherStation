#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include "internationalization.h";
using namespace std;

ReadData::ReadData() {}
void ReadData::ReadEnglishContents(string filename, int records) {
	ifstream output;
	output.open(filename, ios::in);

	if (!output.is_open())
	{
		cout << "File can't open.";
	}

	char str[255];
	while (!output.eof()) {

		output.getline(str, 255); // delim defaults to '\n'
		if (output) {
			cout << str << endl;
		}
		else
		{
			cout << "No Weather Record Found!";
		}
	}
	output.close();
}

void ReadData::ReadLatincontents(string filename, int records) {
	ifstream output;

	output.open(filename, ios::in);

	if (!output.is_open())
	{
		cout << "File can't open.";
	}

	char str[255];
	while (!output.eof()) {

		output.getline(str, 255);
		if (output) {
			cout << str << endl;
		}
		else
		{
			cout << "No Weather Record Found!";
		}
	}
	output.close();
}