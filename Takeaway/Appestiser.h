#pragma once
#include "Item.h"
#include<string>
#include <vector>


class Appetiser : public Item
{
	public:
		bool sharable;
		bool twoForOne;

		Appetiser(vector<string> appInfo);

		virtual string toString();
		virtual bool isTwoForOne();
};

