#include "Order.h"
#include "Appestiser.h"
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

void Order:: add(Item* itemToAdd)
{
	//add the selected choice to the 'items' vector
	items.push_back(itemToAdd);

	//update total price
	total = total + itemToAdd->getItemPrice();

	//display to the user the item that has just been added
	cout << itemToAdd->getItemName() + " added to order!\n";
}

void Order:: remove(Item* itemToRemove)
{
	//bool to track whether the item had been removed from the basket
	removed = false;

	for (int i = 0; i < items.size(); i++)
	{
		//checks teh selected item to remove against all the items in the basket
		//if an item matches then it is removed
		if (itemToRemove->getItemName() == items[i]->getItemName())
		{
			removed = true;

			//reases the item from the vector
			items.erase(items.begin() + i);			

			//updates total *ERROR IF ADD AND REMOVE 7 OBJECTS*
			//total = total - itemToRemove->getItemPrice();

			//displays what was removed from the order and exits loop
			cout << itemToRemove->getItemName() + " removed from order.\n";
			break;
		}
	}

	//outside the loop to make sure it doesn't display multiple times
	if (removed == false)
	{
		cout << "That item is not in your basket. Please try again.\n";
	}

	//Updated Total calculator 
	total = 0;
	//Re add up all current items
	for (int i = 0; i < items.size(); i++)
	{
		total = total + items[i]->getItemPrice();
	}
}

void Order::calculateTotal()
{
	//a vector to hold all items tagged as 2-4-1
	vector<float> twoForOneItems;

	for (int i = 0; i < items.size(); i++)
	{
		//loops through all items in the basket and pulls out all the appetisers that are tagged 2-4-1 
		if ((items[i]->getItemType() == "a") && (dynamic_cast<Appetiser*>(items[i])->isTwoForOne() == true))
		{
			//add them to the new vector
			twoForOneItems.push_back(items[i]->getItemPrice());
		}
	}

	
	if (twoForOneItems.size() > 1)
	{
		//if there is more than 1 item in the basket tagged 2-4-1, activate the 2-4-1 calculation
		hasTwoForOne = true;
		twoForOneCalc(twoForOneItems);
	}

	toString();
}

void Order::twoForOneCalc(vector<float> twoForOneSavings)
{
	//function to calculate the savings from the 2-4-1 deal
	savings = 0;

	//sorts the 2-4-1 items from most expensive to least expensice 
	sort(twoForOneSavings.begin(), twoForOneSavings.end(), greater<int>());

	//variable just to store the size of the vector
	int vectorLength = twoForOneSavings.size();

	int halfway = 0;

	//check to see if there is an even amount of items in the vector
	if (vectorLength % 2 != 0)
	{
		vectorLength++;
	}

	//find the half way point of the vector
	halfway = (vectorLength / 2);

	//iterate through adding the prices of the items that will not be counted towards the total
	for (int i = halfway; i < twoForOneSavings.size(); i++)
	{
		savings = savings + twoForOneSavings[i];
	}
}

void Order::toString()
{
	cout << "\n===== Checkout =====\n";
	
	//a string used to hold all text for the reciept
	recieptString = "";

	//append all items in the basket onto the order string
	for (int i = 0; i < items.size(); i++)
	{
		recieptString.append("(" + to_string(i + 1) + ") " + items[i]->toString() + "\n");
	}

	//update the final total by applying the 2-4-1 saving
	finalTotal = total - savings;

	//convert the strings into stringstreams in order to be able to display the float values without the excess 0's
	stringstream finalTotalStream;
	stringstream savingsStream;

	finalTotalStream << finalTotal;
	savingsStream << savings;

	string finalTotalString = finalTotalStream.str();
	string savingsString = savingsStream.str();

	recieptString.append("-------------\n");

	//display the 2-4-1 savings IF there are any applied
	if (hasTwoForOne)
	{
		recieptString.append("2-4-1 discount applied! Savings: $" + savingsString + "\n");
	}
	
	recieptString.append("Total: $" + finalTotalString + "\n");

	cout << recieptString;
}

void Order::PrintReceipt()
{
	//use the complete and formatted recieptString to create a reciept file
	ofstream reciptFile("receipt.txt");
	reciptFile << recieptString;
	reciptFile.close();
}

void Order:: Checkout()
{
	calculateTotal();
}

