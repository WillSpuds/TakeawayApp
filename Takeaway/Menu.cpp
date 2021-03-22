#include "Menu.h"
#include "Appestiser.h"
#include "MainCourse.h"
#include "Beverage.h"

Menu :: Menu(string fileName)
{
	//On initialisation real the file
	ReadFile(fileName);
}

//initialise the 2D array and default row/column positions
string menuElements[8][12];
int rowID = 0;
int columnID = 0;

void Menu :: ReadFile(string fileName)
{
	//strings to hold the current line and element
	string currentLine;
	string currentElement;
	
	ifstream fileToRead(fileName);

	//check if the file exists
	if (fileToRead)
	{
		//look at the whole line of the menu
		while (getline(fileToRead, currentLine))
		{
			//convert the current line into a stringStream to breakdown further
			istringstream CurrentLineTemp(currentLine);

			//break the line down between the commas
			while (getline(CurrentLineTemp, currentElement, ','))
			{
				//add each element of the table into this new table to store the menu elements in a 2D array
				menuElements[columnID][rowID] = currentElement;

				//temporerily store the line in a vector
				currentItemVector.push_back(currentElement);

				//next column
				columnID++;
			}
			
			//Create Item using the current item vector and array
			CreateItem(menuElements);

			//Go to next row and reset
			rowID++;
			columnID = 0;
			currentItemVector.clear();
		}
		//close the menu file
		fileToRead.close();
	}
	else
	{
		cout << "File does not exist.\n";
	}
}

void Menu :: CreateItem(string array[8][12])
{
	//look at the first character in the row to determine which type of item to create
	//once created, add to the item list
	if (array[0][rowID].compare("a") == 0)
	{
		//Create Appetiser
		Appetiser* appPoint = new Appetiser(currentItemVector);
		items.push_back(appPoint);
	}
	else if (array[0][rowID].compare("m") == 0)
	{
		//Create Main
		MainCourse* mainPoint = new MainCourse(currentItemVector);
		items.push_back(mainPoint);
	}
	else if (array[0][rowID].compare("b") == 0)
	{
		//Create Bev
		Beverage* bevPoint = new Beverage(currentItemVector);
		items.push_back(bevPoint);
	}
}

void Menu::toString()
{
	//used to display the menu to the user
	cout << "_____________Appetisers_____________\n";
	int i = 0;
	while (i < items.size() && items[i]->getItemType() == "a")
	{
		//to display the menu number of the item which is not found in the file
		string MenuNumString = to_string(i + 1);

		//display the number and get the item to display itself
		cout << ("(" + MenuNumString + ")" + items[i]->toString()) << endl;

		i++;
	}
	//repeat for other item types

	cout << "________________Main________________\n";
	while (i < items.size() && items[i]->getItemType() == "m")
	{
		string MenuNumString = to_string(i + 1);

		cout << ("(" + MenuNumString + ")" + items[i]->toString()) << endl;

		i++;
	}

	cout << "________________Bevs________________\n";
	while (i < items.size() && items[i]->getItemType() == "b")
	{
		string MenuNumString = to_string(i + 1);

		cout << ("(" + MenuNumString + ")" + items[i]->toString()) << endl;

		i++;
	}
}

Item* Menu::getChoice(int option) 
{
	//a function to return the chosen menu choice as an item
	if (option > items.size())
	{
		return NULL;
	}
	else
	{
		Item* itemToReturn = items[option];
		return itemToReturn;
	}
}





