#pragma once
#include "Item.h"
#include<string>
#include <vector>

class MainCourse : public Item
{
	public:
		MainCourse(vector<string> mainInfo);

		virtual string toString();
};

