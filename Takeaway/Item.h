#pragma once
#include<string>
#include<vector>

using namespace std;

class Item
{
	public:
		string type;

		string calories;
		
		string name;
		
		string price;

		virtual string toString();
		
		Item();

		Item(vector<string> itemInfo);

		string getItemType();

		string getItemName();

		float getItemPrice();
};

