#pragma once

#include "Car.h"

class Seat : public Car
{
public:
	virtual double getFuelCapacity() const override;
	virtual double getFuelConsumption() const override;
	virtual double getAverageSpeed(Weather weather) const override;
};