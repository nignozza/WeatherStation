// wind.h
#ifndef WIND_H_
#define WIND_H_
# include <iostream>
using namespace std;
// wind_t class to hold data about wind and perform operations on wind
class wind_t
{
private:
	double speed;
	string direction;
public:
	wind_t();
	wind_t(double, string);
	void setWindSpeed(double);
	void setWindDirection(string);
	double getWindSpeed();
	string getWindDirection();
	void displayWind();
	void displayWindF();
};
#endif /* WIND_H_ */