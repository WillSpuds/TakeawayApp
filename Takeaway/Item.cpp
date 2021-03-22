#include "Item.h"
#include <iostream>

Item::Item(vector<string> itemInfo)
{
	//constructor reads the line from the menu and stores each of the elements details in the objects variables
	type = itemInfo[0];
	name = itemInfo[1];
	price = itemInfo[2];
	calories = itemInfo[3];
}

Item::Item()
{
	//base constructor
}

string Item::toString()
{
	//format the data into the correct style string
	return name + ": $" + price + " " + calories + " cal ";	
}

//a series of functions that just return the specified item info
string Item::getItemType()
{
	return type;
}

string Item::getItemName()
{
	return name;
}

float Item::getItemPrice()
{
	return stof(price);
}
