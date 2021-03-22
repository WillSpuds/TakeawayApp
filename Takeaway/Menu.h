#pragma once
#include "ItemList.h"
#include "Appestiser.h"
#include "MainCourse.h"
#include "Beverage.h"

#include <sstream>
class Menu : public ItemList
{
	public:
		Menu(string fileName);

		void toString();

		Item* getChoice(int option);

		vector<string> currentItemVector;
		

	private:
		void ReadFile(string fileName);

		void CreateItem(string array[8][12]);
};

