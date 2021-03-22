#include "Beverage.h"
#include <string>
#include <vector>
#include <iostream>

Beverage :: Beverage(vector<string> bevInfo)
{
	type = bevInfo[0];
	name = bevInfo[1];
	price = bevInfo[2];
	calories = bevInfo[3];
	volume = bevInfo[6];
	abv = bevInfo[7];
}

bool Beverage :: isAlcoholic()
{
	bool isAlcoholic = false;
	if (abv != "0")
	{
		isAlcoholic = true;
	}
	return isAlcoholic;
}

string Beverage::toString()
{
	string bevString = name + ": $" + price + " " + calories + "cal (" + volume + "ml, " + abv + "% abv)";

	return bevString;
}

