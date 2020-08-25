#ifndef Beverage_H
#define Beverage_H

#include<string>
#include<vector>
using namespace std;
#include "Ingredient.h"

//Helper Class for ingredients information of a beverage
class Beverage {
public:
	string name;
	vector<Ingredient>ingredients;

	Beverage(string name, vector<Ingredient>ingredients) {
		this->name = name;
		this->ingredients = ingredients;
	}

	string getName() {
		return name;
	}

	vector<Ingredient> getIngredients() {
		return ingredients;
	}
};


#endif