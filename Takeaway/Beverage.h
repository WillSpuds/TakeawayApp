#pragma once
#include "Item.h"
#include<string>
#include <vector>

class Beverage : public Item
{
	public:
		string volume;
		string abv;

		Beverage(vector<string> bevInfo);

		bool isAlcoholic();

		virtual string toString();
};

