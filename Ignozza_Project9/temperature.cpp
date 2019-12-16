#include "stdafx.h"
# include "temperature.h"
// default constructor
temperature_t::temperature_t()
{}
//parameterized constructor
temperature_t::temperature_t(int temperature)
{
	temperature_t::temperature = temperature;
}
// setters
void temperature_t::setTemperature(int temperature)
{
	temperature_t::temperature = temperature;
}
// getters
int temperature_t::getTemperature()
{
	return temperature;
}
// display temperature object
void temperature_t::displayTemperature()
{
	cout << "Temperature " << temperature << "\n";
}
void temperature_t::displayTemperatureF()
{
	cout << "Température " << temperature << "\n";
}