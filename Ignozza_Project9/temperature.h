// temperature.h
#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_
# include <iostream>
using namespace std;
// class to store details of temperature and provide operations on temperature object
class temperature_t {
private:
	int temperature;
public:
	temperature_t();
	temperature_t(int);
	void setTemperature(int);
	int getTemperature();
	void displayTemperature();
	void displayTemperatureF();
};
#endif /* TEMPERATURE_H_ */