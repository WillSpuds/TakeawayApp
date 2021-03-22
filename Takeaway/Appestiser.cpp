#include "Appestiser.h"
#include <string>
#include <vector>
#include <iostream>

Appetiser :: Appetiser(vector<string> appInfo)
{
	type = appInfo[0];
	name = appInfo[1];
	price = appInfo[2];
	calories = appInfo[3];
	
	//convert the two bool values
	if (appInfo[4] == "y")
	{
		sharable = true;
	}
	else
	{
		sharable = false;
	}

	if (appInfo[5] == "y")
	{
		twoForOne = true;
	}
	else
	{
		twoForOne = false;
	}
}

string Appetiser :: toString()
{ 
	string appString = name + ": $" + price + " " + calories + " cal ";

	//Append on any additional Info
	if(sharable)
	{
		appString.append(" (Sharable) ");
	}

	if(twoForOne)
	{
		appString.append(" (2-4-1) ");
	}

	return appString;
}

bool Appetiser::isTwoForOne()
{
	return twoForOne;
}

