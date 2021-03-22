#include "MainCourse.h"
#include <string>
#include <vector>
#include <iostream>

MainCourse :: MainCourse(vector<string> mainInfo)
{
	type = mainInfo[0];
	name = mainInfo[1];
	price = mainInfo[2];
	calories = mainInfo[3];
}

string MainCourse::toString()
{
	string mainString = name + ": $" + price + " " + calories + " cal ";

	return mainString;
}
