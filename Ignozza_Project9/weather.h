// weather.h
#ifndef WEATHER_H_
#define WEATHER_H_
# include<iostream>
# include "wind.h"
# include "temperature.h"
using namespace std;
// class to store details of weather
class weather_t
{
private:
	wind_t wind;
	temperature_t temperature;
public:
	weather_t();
	weather_t(double speed, string direction, int temperature);
	void setWeatherWind(double speed, string direction);
	void setWeatherTemperature(int temperature);
	wind_t getWeatherWind();
	temperature_t getWeatherTemperature();
	void printWeather(int);
};
#endif /* WEATHER_H_ */