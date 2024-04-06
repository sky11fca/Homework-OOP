#pragma once

#include "Car.h"
#include "Weather.h"
#include <vector>
#include <iostream>

using namespace std;

class Circuit
{
private:
	double length;
	Weather weather;
	vector<Car*> cars;

public:
	Circuit();
	~Circuit();

	void SetLength(double length);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowLosers();

}