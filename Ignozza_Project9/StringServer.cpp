#include "stdafx.h"
#include<iostream>
#include"StringServer.h";
using namespace std;

StringServer::StringServer()
{}

int StringServer::selectLanguage()
{
	int choice = 1;
	do {
		cout << "*****************************************************************************\n";
		cout << "*                                                                           *\n";
		cout << "*                                                                           *\n";
		cout << "****************** WELCOME TO WEATHER STATION SYSTEM ************************\n";
		cout << "*************************** SELECT LANGUAGE *********************************\n";
		cout << "*                                                                           *\n";
		cout << "*****************************************************************************\n\n";
		cout << "1. To select English" << endl;
		cout << "2. To select French" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
	} while (!(choice == 1 || choice == 2));

	return choice;
}