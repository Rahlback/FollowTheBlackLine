#include <iostream>
#include <string>
#include <vector>
#include "LilRobot.h"
#include <algorithm>
#include "yourSolution.h"

std::vector<Map> maps;

Map firstMap = {
	"270wwwwwwwwwwwwwwwwwwwwwwwwwwwww", // Row 0
	"w                              w",
	"w                         E    w",
	"w                         x    w",
	"w                         x    w",
	"w                         x    w",
	"w                         x    w",
	"w       xxxxxxxxxxxxxxxxxxx    w",
	"w       x                      w",
	"w       xxxxxx                 w",
	"w            xx                w",
	"w             x                w",
	"w             x                w", // Row 12
	"w          xxxx                w",
	"w          x                   w", // Row 14, col 11
	"w          S                   w",
	"w                              w",
	"w                              w",
	"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
};

Map secondMap = {
	"270wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
	"w                                                              w",
	"w             E                                                w",
	"w             x                                                w",
	"w             x                                                w",
	"w             xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx               w",
	"w                                              x               w",
	"w                                              x               w",
	"w                                              x               w",
	"w                                              x               w",
	"w                                              x               w",
	"w                                              x               w",
	"w                                              x               w",
	"w                                              x               w",
	"w                         xxxxxxxxxxxxxxxxxxxxxx               w",
	"w                         x                                    w",
	"w                         x                                    w",
	"w                         x                                    w",
	"w                         x                                    w",
	"w                         x                                    w",
	"w                         x                xxxxxxxxxx          w",
	"w                         x                x        x          w",
	"w                         x                x        x          w",
	"w                         x                x        x          w",
	"w                         x                x        x          w",
	"w                         x                x        x          w",
	"w                         x                x        x          w",
	"w                         xxxxxxxxxxxxxxxxxx        x          w",
	"w                         xx                        x          w",
	"w                                                   x          w",
	"w                                                   x          w",
	"w                                                   x          w",
	"w                                                   x          w",
	"w                                                   x          w",
	"w                                                   x          w",
	"w                          xxxxxxxxxxxxxxxxxxxxxxxxxx          w",
	"w                          x                                   w",
	"w                          x                                   w",
	"w                          x                                   w",
	"w                          x                                   w",
	"w                          x                                   w",
	"w                          x                                   w",
	"w                          x                                   w",
	"w                          x                                   w",
	"w                          x                                   w",
	"w                          S                                   w",
	"w                                                              w",
	"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
};

Map thirdMap = {
	"000wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
	"W                                                                                                                              w",
	"W                                                                                                                              w",
	"W                                                                                                                              w",
	"W                                                                                                                              w",
	"W                                                                                                                              w",
	"W                                                                                                                              w",
	"W           xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                               xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx       w",
	"W           x                                     x                               x                                    x       w",
	"W           x                                     x                               x                                    x       w",
	"W           x                                     x                               x                                    x       w",
	"W           x                                     x                               x                                    x       w",
	"w           x                                     x                               x                                    x       w",
	"w           x            xxxxxxxxxxxxxxxxxxxxxxxxxx                               x                                    x       w",
	"w           E            x                                                        xxxxxxxxxxxxxxxx                     x       w",
	"w                        x                                                                       x                     x       w",
	"w                        x                                                                       x                     x       w",
	"w                        x                                                                       x                     x       w",
	"w                        x                                                                       x                     x       w",
	"w                        x                                                                       x                     x       w",
	"w                        x                                                                       x                     x       w",
	"w                        x                                                                       x                     x       w",
	"w                        x                            xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                     x       w",
	"w                        x                            x                                                                x       w",
	"w                        xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                x       w",
	"w                                                                                                                      x       w",
	"w                                                                                                                      x       w",
	"w                                                                                                                      x       w",
	"w                                                                                                                      x       w",
	"w                                                                                                                      x       w",
	"w                                                                                                                      x       w",
	"w          Sxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx       w",
	"w                                                                                                                              w",
	"w                                                                                                                              w",
	"w                                                                                                                              w",
	"w                                                                                                                              w",
	"w                                                                                                                              w",
	"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
};

bool atEnd(const Pos& pos, const Pos& endPos) {
	bool atEndVar = (endPos.x >= pos.x - 1.0 && endPos.x <= pos.x + 1.0) &&
					(endPos.y >= pos.y - 1.0 && endPos.y <= pos.y + 1.0);
	return atEndVar;
}

bool isWithinBounds(const Pos& pos, const Map& map) {
	double width = map.at(0).size();
	double height = map.size();

	bool withinBounds = (pos.x > 0 && pos.x < width) &&
						(pos.y > 0 && pos.y < height);

	return withinBounds;
}

void followTheBlackLine(Map usedMap) {


	
	Pos endPos{ 27.0 , 2.0 }; // This will be overwritten by the for loop below

	// std::pair<double, double> direction = {  0.0,  1.0 };
	std::string directionString = usedMap.at(0).substr(0, 3);

	int direction = std::stoi(directionString);
	std::cout << directionString << std::endl;
	Map robotWalkingMap = usedMap;

	double startX{ 0 };
	double startY{ 0 };
	for (int y = 0; y < usedMap.size(); y++) {
		for (int x = 0; x < usedMap.at(0).size(); x++) {
			if (usedMap.at(y).at(x) == 'S') {
				startX = x + 0.5;
				startY = y + 0.5;
				usedMap.at(y).at(x) = 'x';
				std::cout << "Starting " << x << " " << y << std::endl;
			}
			if (usedMap.at(y).at(x) == 'E') {
				endPos.x = x + 0.5;
				endPos.y = y + 0.5;
			}
		}
	}

	Pos pos = { startX, startY };
	LilRobot robot(pos, direction, 0.5);
	std::cout << "Start: " << robot.pos.x << " " << robot.pos.y << std::endl;
	int stepsDebug = 100;
	bool debug = true;
	int i = 0;
	while (!atEnd(pos, endPos) && isWithinBounds(pos, usedMap)) {
		double sensorVal = robot.calculateSensorValue(usedMap); // Certainty of X underneath
		std::vector<int> returnAction = takeAction(sensorVal);
		
		robot.takeAction(returnAction);
		
		int x = round(robot.pos.x);
		int y = round(robot.pos.y);
		// std::cout << x << " " << y << ", sensor value" << sensorVal << ", " << robot.directionDegrees << ", directionModifier = " << returnAction.at(1) << std::endl;
		// std::cout << robot.pos.x << " " << robot.pos.y << std::endl;
		
		if (!isWithinBounds({double(x), double(y)}, usedMap)) {
			std::cout << "Robot wandered to the edge of the map and got lost" << std::endl;
			break;
		}
		robotWalkingMap.at(y).at(x) = 'R';
		if (i == stepsDebug && debug) {
			Map revWalkingMap = robotWalkingMap;
			std::cout << std::endl;
			std::reverse(revWalkingMap.begin(), revWalkingMap.end());
			for (std::string line : revWalkingMap) {
				std::cout << line << std::endl;
			}
			i = 0;
		}
		i++;
		pos = robot.pos;
	}


	std::cout << "Original map" << std::endl;
	Map revOriginMap = usedMap;
	std::reverse(revOriginMap.begin(), revOriginMap.end());
	for (std::string line : revOriginMap) {
		std::cout << line << '\n';
	}


	std::cout << "\nFinal result!" << std::endl;
	Map revWalkingMap = robotWalkingMap;
	std::reverse(revWalkingMap.begin(), revWalkingMap.end());
	for (std::string line : revWalkingMap) {
		std::cout << line << '\n';
	}
	std::cout << std::endl;


}

int main() {
	Map usingMap;
	int mapNum = mapToUse();
	switch (mapNum) {
		case 0:
			usingMap = firstMap;
			break;
		case 1:
			usingMap = secondMap;
			break;
		case 2:
			usingMap = thirdMap;
			break;
	}

	followTheBlackLine(usingMap);

	return 0;
}