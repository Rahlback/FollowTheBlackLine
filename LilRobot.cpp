#include <iostream>
#include "LilRobot.h"
#include <cmath>

LilRobot::LilRobot(Pos pos, int directionDegrees, double speed)
{
	this->pos = { pos.x, pos.y };
	this->directionDegrees = directionDegrees;
	this->speed = speed;
}


double LilRobot::calculateSensorValue(const Map& map) {
	double sensorWidth{ 0.5 }; // Not really used. This has been used to calculate spacing of data points

	int numOfDataPoints{ 16 };
	double spacingOfDataPoints{ 0.125 };

	double xTiles{ 0 };
	int tiles{ 0 };

	for (int subY = -numOfDataPoints / 8; subY < numOfDataPoints / 8; subY++) {
		for (int subX = -numOfDataPoints / 8; subX < numOfDataPoints / 8; subX++) {
			int realX = floor(this->pos.x + subX * spacingOfDataPoints);
			int realY = floor(this->pos.y + subY * spacingOfDataPoints);
			// std::cout << "( " << realX << ", " << realY << " )" << "\n";
			if (map.at(floor(realY)).at(floor(realX)) == 'x')
				xTiles++;
			tiles++;
		}
	}
	// std::cout << tiles << std::endl;
	double sensorValue = xTiles / tiles;
	return sensorValue;
}

int LilRobot::takeAction(std::vector<int> action)
{
	// Calculate new direction
	int speed = action.at(0);
	int directionModifier = action.at(1);

	bool breakAction = false;
	if (speed < 0 || speed > 10) {
		std::cout << "Invalid speed! Speed has to be between 0 - 10, inclusive.";
		std::cout << " Attempted speed = " << speed << std::endl;
		breakAction = true;
	}
	if (directionModifier > 90 || directionModifier < -90) {
		std::cout << "Invalid direction! Direction has to be between 90 and -90 degrees.";
		std::cout << " Attempted direction = " << directionModifier << std::endl;
		breakAction = true;
	}
	if (breakAction) return -1;

	int newDirection = this->directionDegrees + directionModifier;
	if (newDirection < 0) newDirection += 360;
	if (newDirection >= 360) newDirection -= 360;

	this->directionDegrees = newDirection;
	this->speed = speed / 20.0;

	// speed * sin direction = y
	// speed * cos direction = x
	double PI = 3.14159265359;
	double xDelta = this->speed * cos(this->directionDegrees * PI / 180);
	this->pos.x = xDelta + this->pos.x;

	double yDelta = this->speed * sin(this->directionDegrees * PI / 180);
	this->pos.y = yDelta + this->pos.y;

	// std::cout << "Delta: " << xDelta << " " << yDelta << std::endl;
	return 0;
}
