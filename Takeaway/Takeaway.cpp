/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "Takeaway" assignment
Winter 2020

Written by James Brown

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "ItemList.h"
#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>

#include<list>
#include<fstream>
#include<string>


void PrintTitle(string title)
{
	//Simple function to display headers and titles
	cout << "----------------" + title + "----------------\n";
}

bool isInt(string stringToCheck) 
{
	//function to check if a string is an integer, used when checking user input
	bool isStringInt = false;

	//go along the given string running the isDigit method
	for (int i = 0; i < stringToCheck.size(); i++)
	{
		isStringInt = isdigit(stringToCheck[i]);
	}

	return isStringInt;
}

void displayIntro()
{
	//simple function to inform user how to use app
	cout << "Welcome to the take-away food ordering system! \n";
	cout << "Type MENU to see our current menu of food available. \n";
	cout << "To select items to add to your basket, type ADD followed by the numbers of the items on the menu. \n";
	cout << "Similarly to remove an item type REMOVE followed by the corresponding number. \n";
	cout << "If you choose to exit the application type EXIT.\n";
	cout << "--------------------------------------------------\n";
}

void PrintHelp()
{
	//Explain how to use the app by using the intro messge again
	PrintTitle("Help");
	displayIntro();
}

int main()
{
	displayIntro();

	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char * token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) 
		{
			//display Menu
			menu.toString();
		}
		else if (command.compare("add") == 0)
		{	
			//iterate through all given parameters
			for (int i = 1; i < parameters.size(); i++)
			{

				if (parameters.size() == 1)
				{
					//a single parameter is not a correct input
					cout << "That is not on the menu. Please try again.\n";
				}
				else
				{
					//check if the user has inputted a digit to add to the basket
					if (isInt(parameters[i]) == true)
					{
						//create the item object to hold the users current choice
						Item* choice = menu.getChoice(stoi(parameters[i]) - 1); 

						if (choice == NULL)
						{
							//invalid input
							cout << "That is not on the menu. Please try again.\n";
						}
						else
						{
							//add to basket
							order.add(choice);
						}
					}
					else
					{
						cout << "That is not on the menu. Please try again.\n";
					}
				}				
			}			
		}
		else if (command.compare("remove") == 0)
		{
			//similarly to how to add takes mulitple parameters
			for (int i = 1; i < parameters.size(); i++)
			{
				if (parameters.size() == 1)
				{
					cout << "That is not on the menu. Please try again.\n";
				}
				else
				{
					if (isInt(parameters[i]) == true)
					{
						Item* removeChoice = menu.getChoice(stoi(parameters[i]) - 1);

						if (removeChoice == NULL)
						{
							cout << "That is not in your basket. Please try again.\n";
						}
						else
						{
							//remove from basket
							order.remove(removeChoice);
						}
					}
					else
					{
						cout << "That is not in your basket. Please try again.\n";
					}
				}
			}
		}
		else if (command.compare("checkout") == 0)
		{
			//calculates current price
			order.Checkout();

			//take user input to for if they want to continue with purchase
			string checkoutConfirmation = "";

			cout << "Do you want to place your order? \n Type 'y' to confirm, or 'n' to go back and modify it.\n";

			//a while loop to make sure the user only uses either y or n for their descision
			while (checkoutConfirmation != "y" && checkoutConfirmation != "n")
			{
				getline(cin, checkoutConfirmation);

				if (checkoutConfirmation == "y")
				{
					//print the reciept and exit app
					order.PrintReceipt();
					cout << "Your order has been complete!\n";
					userCommand = "exit";
				}
				else if (checkoutConfirmation == "n")
				{
					//exits loop without executing any further action
				}
				else
				{
					cout << "Please input either y or n.\n";
				}
			}
		}
		else if (command.compare("help") == 0)
		{
			//Displays help screen
			PrintHelp();
		}
		else
		{
			if (command.compare("exit") != 0)
			{
				cout << "Please use one of the approved commands. Type HELP for assistance.\n";
			}
		}

		parameters.clear();
	}

	cout << "Press any key to quit...";
	std::getchar();
}