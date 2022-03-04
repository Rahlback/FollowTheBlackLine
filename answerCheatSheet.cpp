#include <vector>


// This will work, but won't be pretty
//std::vector<int> takeAction(double sensorValue) {
//	// std::vector<int> returnV = {SPEED (0   10),  
//	//							   DIRECTION(  1 to  90 = left, 0 = forward, 1 to 90 = right)
//	//                             
//	// SPEED will be divided by 20, since the maximum speed allowed is 0.5 'pixels' per move
//	// The direction is in degrees, with 0 being the forward facing of the robot
//
//	int speed = 1;
//	int direction = 0;
//	if (sensorValue < 0.3) {
//		direction = 2;
//	}
//	else if (sensorValue > 0.7) {
//		direction = 2;
//	}
//
//
//	return { speed, direction };
//}