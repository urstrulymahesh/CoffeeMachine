#ifndef CoffeeMachine_H
#define CoffeeMachine_H

#include<string>
#include<vector>
#include<map>
#include<exception>
#include<mutex>
#include <iostream>
using namespace std;
#include"Beverage.h"
#include "Ingredient.h"
#include "IngredientNotAvailableException.h"
#include "InsufficientQuantityException.h"

//Class for CoffeeMachine
class CoffeeMachine {
	mutex m;
public:
	int numOfOutlets;
	map<string, int> Stock; //to store available ingredients stock information in the coffee machine
	map<string, Beverage> beverages; //to store ingredient information of all beverages

	CoffeeMachine(int numOfOutlets, vector<Ingredient> Stock, vector<Beverage> beverages) {
		this->numOfOutlets = numOfOutlets;

		for (int i = 0; i < Stock.size(); i++) {
			this->Stock.insert(pair<string, int>(Stock[i].getName(), Stock[i].getQuantity()));
		}

		for (int i = 0; i < beverages.size(); i++) {
			this->beverages.insert(pair<string, Beverage>(beverages[i].getName(), beverages[i]));
		}
	}

	//Helper function to refill ingredients in the Stock of CoffeeMachine
	void RefillIngredients(vector<Ingredient> fill) {
		for (int i = 0; i < fill.size(); i++) {
			if (Stock.find(fill[i].getName()) != Stock.end()) {
				Stock.find(fill[i].getName())->second += fill[i].getQuantity();
			}
			else Stock.insert(pair<string, int>(fill[i].getName(), fill[i].getQuantity()));
			cout << "Refill " << fill[i].getName() << " with " << fill[i].getQuantity() << " units completed" << endl;
		}
	}

	Beverage DispenseBeverage(string BeverageName) {
		Beverage beverage = beverages.find(BeverageName)->second;
		ConsumeBeverageIngredients(beverage);
		return beverage;
	}

	//Helper function to prepare beverage by consuming ingredients
	void ConsumeBeverageIngredients(Beverage beverage) {
		vector<Ingredient> ingredients = beverage.getIngredients();

		//Check availability of all ingredients. mutex lock is not required here as it only checks the availability
		for (int i = 0; i < ingredients.size(); i++) {
			try
			{
				if (Stock.find(ingredients[i].getName()) == Stock.end()) {
					throw IngredientNotAvailableException(beverage.getName(), ingredients[i].getName());
				}
			}
			catch (IngredientNotAvailableException & e) {
				cerr << e.what() << endl;
				return;
			}
		}

		m.lock();
		//Check whether ingredient are present in stock in sufficient quantity
		for (int i = 0; i < ingredients.size(); i++) {
			int AvailableQuantity = Stock.find(ingredients[i].getName())->second;
			try {
				int RequiredQuantity = ingredients[i].getQuantity();
				if (RequiredQuantity > AvailableQuantity) {
					throw InsufficientQuantityException(beverage.getName(), ingredients[i].getName());
				}
			}
			catch (InsufficientQuantityException & e) {
				cerr << e.what() << endl;
				//unlock the mutex as the beverage cannot be prepared because of insufficient ingredient quantity.
				m.unlock();
				return;
			}
		}

		//Consume the ingredients and prepare the beverage only if all ingredients are in sufficient quantity.
		for (int i = 0; i < ingredients.size(); i++) {
			int AvailableQuantity = Stock.find(ingredients[i].getName())->second;
			int RequiredQuantity = ingredients[i].getQuantity();
			try {
				Stock[ingredients[i].getName()] = AvailableQuantity - RequiredQuantity;
			}
			catch (exception & e) {
				cerr << e.what() << endl;
				//unlock the mutex because of unknown exception.
				m.unlock();
				return;
			}
		}
		//unlock the mutex after successful preparation.
		m.unlock();
		cout << beverage.getName() + " is prepared" << endl;
	}
};



#endif