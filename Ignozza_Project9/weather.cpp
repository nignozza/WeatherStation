#include "stdafx.h"
#include "weather.h"
// default constructor

weather_t::weather_t()
{}
// parameterized constructor
weather_t::weather_t(double speed, string direction, int temp)
{
	this->wind.setWindSpeed(speed);
	this->wind.setWindDirection(direction);
	this->temperature.setTemperature(temp);
}
// setters
void weather_t::setWeatherTemperature(int temperature)
{
	this->temperature.setTemperature(temperature);
}

void weather_t::setWeatherWind(double speed, string direction)
{
	this->wind.setWindDirection(direction);
	this->wind.setWindSpeed(speed);
}
// getters
wind_t weather_t::getWeatherWind()
{
	return wind;
}
temperature_t weather_t::getWeatherTemperature()
{
	return temperature;
}
// display weather object
void weather_t::printWeather(int language)
{
	temperature.displayTemperature();
	if (language == 1)
		wind.displayWind();
	else
		wind.displayWindF();

	cout << "\n";
}