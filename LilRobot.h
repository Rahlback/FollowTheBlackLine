#pragma once
#include <vector>

typedef std::vector<std::string> Map;

/// <summary>
/// A coordinate object. Contains two values: double x, double y.
/// </summary>
class Pos {
public:
	double x;
	double y;
};

/// <summary>
/// The robot that will navigate a map
/// </summary>
class LilRobot {
public:
	Pos pos;
	int directionDegrees; // 0 - 359
	double speed;

	LilRobot(Pos pos, int directionDegrees, double speed);
	
	/// <summary>
	///	Calculates the sensor value by looking at 16 sub-coordinates around the 
	/// (X, Y) coordinates.
	/// </summary>
	/// <param name="map">Map object containing the map which the robot is on</param>
	/// <returns>A percentage of how much the sensor is over 'x' tiles in the map</returns>
	double calculateSensorValue(const Map& map);

	/// <summary>
	/// The action which the robot should take. Speed and direction is normalized
	/// so that the speed never will be more than 0.5 pixels regardless of direction.
	/// </summary>
	/// <param name="action"></param>
	/// <returns></returns>
	int takeAction(std::vector<int> action);
};