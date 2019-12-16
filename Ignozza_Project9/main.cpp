#include "stdafx.h"
#include "weather.h"
#include <iostream>
#include <conio.h>
#include "internationalization.h";
#include "StringServer.h";
#include<sstream>
using namespace std;
string DisplayMenu(string station_name)
{
	string str, temp;
	do
	{
		cout << "\n*****************************************************************************\n";
		cout << "* *\n";
		cout << "* *\n";
		cout << "*******************WEATHER STATION: " << station_name << "***********************" << endl << endl;
		cout << "* *\n";
		cout << "* *\n";
		cout << "*****************************************************************************\n";
		cout << "1. Input a complete weather reading." << endl;
		cout << "2. Print the current weather." << "\n";
		cout << "3. Print the weather history (from most recent to oldest)." << endl;
		cout << "4. Exit the program." << "\n";
		cout << "Enter your choice: " << endl;
		cin >> str;
		temp = str;
		for (std::string::size_type i = 0; i < str.length(); ++i)
			temp[i] = toupper(str[i]);
		str = temp;
	} while (!(str == "1" || str == "2" || str == "3" || str == "4"));
	return str;
}
double getWindSpeed()
{
	double speed = -1;
	string temp_string;
	stringstream converter;
	//this loop will be iterated continuously untill user enters windspeed which is greater than zero
	do {
		cout << "Enter Wind speed(>=0): ";
		cin >> temp_string;
		stringstream(temp_string) >> speed;
		if (speed < 0)
			cout << "Wind speed should be always greater or equal to 0(zero)";
	} while (speed < 0);
	return speed;
}
string getWindDirection()
{
	string direction;
	do {
		cout << "Enter the Wind Direction (North,South,East,West): ";
		cin >> direction;
		for (std::string::size_type i = 0; i < direction.length(); ++i)
			direction.at(i) = toupper(direction.at(i));
	} while (!(direction == "NORTH" || direction == "SOUTH" || direction == "EAST" || direction == "WEST"));
	return direction;
}
int getTemperature()
{
	int temperature;
	string temp_string;
	stringstream converter;
	cout << "Enter the temperature: ";
	cin >> temp_string;
	converter << temp_string;
	converter >> temperature;
	return temperature;
}
string DisplayMenuF(string station_name)
{
	string str, temp;
	do
	{
		cout << "*******************STATION MÉTÉO: " << station_name\
			<< " *******************" << endl << endl;
		cout << "1. Entrez une lecture complète du temps." << endl;
		cout << "2. Imprime la météo actuelle." << "\n";
		cout << "3. Imprime l'historique météo (du plus récent au plus ancien)." << endl;
		cout << "4. Quittez le programme." << "\n";
		cout << "Entrez votre choix: " << endl;
		cin >> str;
		temp = str;
		for (std::string::size_type i = 0; i < str.length(); ++i)
			temp[i] = toupper(str[i]);
		str = temp;
	} while (!(str == "1" || str == "2" || str == "3" || str == "4"));
	return str;
}
double getWindSpeedF()
{
	double speed = -1;
	string temp_string;
	stringstream converter;
	//this loop will be iterated continuously untill user enters windspeed which is greater than zero
	do {
		cout << "Entrez la vitesse du vent (> = 0): ";
		cin >> temp_string;
		stringstream(temp_string) >> speed;
		if (speed < 0)
			cout << "La vitesse du vent doit toujours être supérieure ou égale à 0 (zéro)";
	} while (speed < 0);
	return speed;
}
string getWindDirectionF()
{
	string direction;
	do {
		cout << "Enter the Wind Direction (Nord, Sud, Est, Ouest): ";
		cin >> direction;
		for (std::string::size_type i = 0; i < direction.length(); ++i)
			direction.at(i) = toupper(direction.at(i));
	} while (!(direction == "NORD" || direction == "SUD" || direction == "EST" || direction == "QUEST"));
	return direction;
}
int getTemperatureF()
{
	int temperature;
	string temp_string;
	stringstream converter;
	cout << "Entrez la température: ";
	cin >> temp_string;
	converter << temp_string;
	converter >> temperature;
	return temperature;
}
int selectLanguage()
{
	int choice;
	cout << "*****************************************************************************\n";
	cout << "* *\n";
	cout << "* *\n";
	cout << "****************** WELCOME TO WEATHER STATION SYSTEM ************************\n";
	cout << "*************************** SELECT LANGUAGE *********************************\n";
	cout << "* *\n";
	cout << "*****************************************************************************\n\n";
	cout << "1. To select English" << endl;
	cout << "2. To select French" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}
int main()
{ //Have the user provide a name for the weather station upon entry.
	StringServer *S_Server = new StringServer(); // Creating String Server Object.
	weather_t *history = new weather_t();
	int choice = S_Server->selectLanguage();
	int historySize;
	string station_name, input_choice;
	int histCount = 0;
	int fileHCount = 0;
	if (choice == 1)
	{
		//char c;
		int i = 0;
		cout << "Enter the name of Weather Station: ";
		int flag = 1;
		while (1)
		{
			getline(cin, station_name);
			if (flag == 2)
				break;
			flag = 2;
		}
		do
		{
			cout << "Please enter how many records you want: ";
			cin >> historySize;
			if (historySize <= 0)
				cout << "Input record count should always be greater than 0(zero)" << "\n";
		} while (historySize <= 0);
		history = new weather_t[historySize];
		while (1)
		{
			//Control loop to perform various actions
			input_choice = DisplayMenu(station_name);
			if (input_choice == "1")
			{
				if (histCount<historySize)
				{
					double speed = getWindSpeed();
					string direction = getWindDirection();
					int temp = getTemperature();
					history[histCount].setWeatherTemperature(temp);
					history[histCount].setWeatherWind(speed, direction);
					histCount++;
				}
				else
					cout << "\n Maximum records entered";
			}
			else if (input_choice == "2")
			{
				cout << "*************Printing Current Weather*************" << endl;
				if (histCount > 0)
				{
					history[histCount - 1].printWeather(1);
				}
				else
				{
					cout << "no data has been entered" << "\n";
				}
			}
			else if (input_choice == "3")
			{
				cout << "*************Printing Weather*************" << endl;
				if (histCount == 0)
					cout << "no data to output" << "\n";
				int max = histCount > historySize ? historySize : histCount;
				for (int i = max - 1; i >-1; i--)
				{
					history[i].printWeather(1);
				}
			}
			else if (input_choice == "4")
			{
				break;
			}
		}
	}
	else if (choice == 2)
	{
		cout << "Entrez le nom de la station météo: ";
		int flag = 1;
		while (1)
		{
			getline(cin, station_name);
			if (flag == 2)
				break;
			flag = 2;
		}
		do
		{
			cout << "Veuillez entrer le nombre d'enregistrements que vous voulez" << "\n";
			cin >> historySize;
			if (historySize <= 0)
				cout << "Le nombre d'enregistrements d'entrée doit toujours être supérieur à 0 (zéro)" << "\n";
		} while (historySize <= 0);
		history = new weather_t[historySize];
		while (1)
		{
			//Control loop to perform various actions
			input_choice = DisplayMenuF(station_name);
			if (input_choice == "1")
			{
				if (histCount<historySize)
				{
					double speed = getWindSpeedF();
					string direction = getWindDirectionF();
					int temp = getTemperatureF();
					history[histCount].setWeatherTemperature(temp);
					history[histCount].setWeatherWind(speed, direction);
					histCount++;
				}
				else
					cout << "\n Nombre maximal d'enregistrements entrés";
			}
			else if (input_choice == "2")
			{
				cout << "*************Impression de la météo actuelle*************" << endl;
				if (histCount > 0)
				{
					history[histCount - 1].printWeather(2);
				}
				else
				{
					cout << "aucune donnée n'a été entrée" << "\n";
				}
			}
			else if (input_choice == "3")
			{
				cout << "*************Impression Météo*************" << endl;
				if (histCount == 0)
					cout << "pas de données à sortir" << "\n";
				int max = histCount > historySize ? historySize : histCount;
				for (int i = max - 1; i >-1; i--)
				{
					history[i].printWeather(2);
				}
			}
			else if (input_choice == "4")
			{
				break;
			}
		}
	}
	else
	{
		cout << "Please make valid selection of language.";
	}
	system("close");
	return 0;
}