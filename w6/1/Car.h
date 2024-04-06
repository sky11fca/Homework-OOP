#pragma once

#include "Weather.h"

class Car
{
public:

	virtual ~Car(){}

	virtual double getFuelCapacity() const = 0;
	virtual double getFuelConsumption() const = 0;
	virtual double getAverageSpeed(Weather weather) const = 0;
};