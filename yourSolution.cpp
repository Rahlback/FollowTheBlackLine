#include "yourSolution.h"



int mapToUse() {
	int mapToUse = 1; // 0, 1, 2
	return mapToUse;
}


double previousSensorVal = 0;

/// <summary>
/// Your solution. Decide what speed and direction the robot should take
/// using the sensor value from the robot. The sensor value is calculated by 
/// checking 16 dots on a grid 0.5 pixels wide and 0.5 pixels high. The sensor value
/// is then the number of dots that are over a 'x' on the map divided by 16.
/// Sensor value = dotsOverX / totalNumOfDots
/// </summary>
/// <param name="sensorValue"></param>
/// <returns></returns>
std::vector<int> takeAction(double sensorValue) {
	// std::vector<int> returnV = {SPEED (0   10),  
	//							   DIRECTION(  1 to  90 = left, 0 = forward, 1 to 90 = right)
	//                             
	// SPEED will be divided by 20, since the maximum speed allowed is 0.5 'pixels' per move
	// The direction is in degrees, with 0 being the forward facing of the robot
	// Change the mapToUse function in order to switch maps
	
	int speed = 5;
	int direction = 0;
	if (sensorValue < 0.3) {
		direction = -10;
	}
	else if (sensorValue > 0.7) {
		direction = 10;
	}

	previousSensorVal = sensorValue;
	return { speed, direction };
}