#include "stdafx.h"
#include <string>
# include "wind.h"
// default constructor
wind_t::wind_t()
{}
// parameterized constructor
wind_t::wind_t(double speed, string direction)
{
	wind_t::speed = speed;
	wind_t::direction = direction;
}
// setters
void wind_t::setWindDirection(string direction)
{
	wind_t::direction = direction;
}
void wind_t::setWindSpeed(double speed)
{
	wind_t::speed = speed;
}
// getters
double wind_t::getWindSpeed()
{
	return speed;
}
string wind_t::getWindDirection()
{
	return direction;
}
// display wind
void wind_t::displayWind()
{
	cout << "Wind Direction " << direction << "\n";
	cout << "Wind Speed " << speed << "\n";
}
void wind_t::displayWindF()
{
	cout << "Direction du vent " << direction << "\n";
	cout << "Vitesse du vent " << speed << "\n";
}