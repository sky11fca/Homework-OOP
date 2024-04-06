#include "Circuit.h"
#include <algorithm>

Circuit::Circuit(): length(0), weather(Weather::Rain){}

Circuit::~Circuit()
{
	for (Car* car : cars)
	{
		delete car;
	}
}

void Circuit::SetLength(double length)
{
	this->length = length;
}

void Circuit::AddCar(Car* car)
{
	cars.push_back(car);
}

void Circuit::Race() {
    std::vector<std::pair<double, Car*>> finishTimes;

    for (Car* car : cars) {
        double time = length / car->getAverageSpeed(weather);
        if (time * car->getFuelConsumption() <= car->getFuelCapacity()) {
            finishTimes.push_back({ time, car });
        }
    }

    sort(finishTimes.begin(), finishTimes.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
        });

    for (const auto& pair : finishTimes) {
        std::cout << pair.second << " finished in " << pair.first << " hours." << std::endl;
    }
}

void Circuit::ShowFinalRanks() {
    std::vector<std::pair<double, Car*>> finishTimes;

    for (Car* car : cars) {
        double time = length / car->getAverageSpeed(weather);
        if (time * car->getFuelConsumption() <= car->getFuelCapacity()) {
            finishTimes.push_back({ time, car });
        }
    }

    sort(finishTimes.begin(), finishTimes.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
        });

    std::cout << "Final Ranks:" << std::endl;
    int rank = 1;
    for (const auto& pair : finishTimes) {
        std::cout << rank << ". " << pair.second << " finished in " << pair.first << " hours." << std::endl;
        rank++;
    }
}

void Circuit::ShowLosers() {
    for (Car* car : cars) {
        double time = length / car->getAverageSpeed(weather);
        if (time * car->getFuelConsumption() > car->getFuelCapacity()) {
            std::cout << car << " did not finish due to insufficient fuel." << std::endl;
        }
    }
}