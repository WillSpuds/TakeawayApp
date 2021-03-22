#pragma once

#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>

#include<list>
#include<fstream>
#include<string>

using namespace std;

class ItemList
{
	public:
		vector <Item*> items;

		void toString();
};

