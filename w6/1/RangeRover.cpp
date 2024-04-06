#include "RangeRover.h"

double RangeRover::getFuelCapacity() const
{
	return 70.0;
}

double RangeRover::getFuelConsumption() const
{
	return 7.5;
}

double RangeRover::getAverageSpeed(Weather weather) const
{
	switch (weather)
	{
	case Weather::Rain:
		return 85.0;
	case Weather::Sunny:
		return 90.0;
	case Weather::Snow:
		return 75.0;
	default:
		return 0.0;
	}
}