#ifndef utils_H
#define utils_H

#include "CoffeeMachine.h"
#include<iomanip>

template<typename T> void print(T t, const int& width, const char& seperator)
{
	cout << left << setw(width) << setfill(seperator) << t;
}

void DisplayInventory(CoffeeMachine& machine) {
	const int width = 20;
	const int numWidth = 9;
	const int div_width = 4;
	const char seperator = ' ';
	map<string, int>::iterator itr;
	for (itr = machine.Stock.begin(); itr != machine.Stock.end(); itr++) {
		print("||", div_width, seperator);
		print(itr->first, width, seperator);
		print("||", div_width, seperator);
		print(itr->second, numWidth, seperator);
		print("||", div_width, seperator);
		if (itr->second == 0)
			print("(LOW)", 6, seperator);
		cout << endl;
	}
	cout << endl;
}

void DisplayBeverage(vector<Beverage>beverages) {
	for (int i = 0; i < beverages.size(); i++) {
		cout << beverages[i].getName() << " :" << endl;
		vector<Ingredient> ingredients = beverages[i].getIngredients();
		for (int j = 0; j < ingredients.size(); j++) {
			cout << "     " << ingredients[j].getName() << " : " << ingredients[j].getQuantity() << endl;
		}
		cout << endl;
	}
}

#endif