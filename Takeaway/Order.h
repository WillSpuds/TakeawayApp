#pragma once
#include "ItemList.h"
class Order : public ItemList
{
	public:
		float total;

		float savings = 0;

		float finalTotal;

		bool removed;

		bool hasTwoForOne = false;

		string recieptString;

		void calculateTotal();
		
		void PrintReceipt();

		void add(Item* itemToAdd);

		void remove(Item* itemToRemove);

		void toString();

		void Checkout();

		void twoForOneCalc(vector<float> twoForOneSavings);
};

