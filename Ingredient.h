#ifndef Ingredient_H
#define Ingredient_H

#include<string>
using namespace std;

//Helper Class for ingredient information.
class Ingredient {
public:
	string name;
	int quantity;
	Ingredient(string name, int quantity) {
		this->name = name;
		this->quantity = quantity;
	}
	string getName() {
		return name;
	}
	int getQuantity() {
		return quantity;
	}
};

#endif