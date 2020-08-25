#ifndef InsufficientQuantityException_H
#define InsufficientQuantityException_H

#include<string>
using namespace std;

//Exception class for ingredient insufficient quantity case
class InsufficientQuantityException {
public:
	InsufficientQuantityException(string BeverageName, string IngredientName) {
		this->BeverageName = BeverageName;
		this->IngredientName = IngredientName;
	}

	string what() {
		return BeverageName + " cannot be prepared because " + IngredientName + " is not sufficient";
	}

private:
	string BeverageName;
	string IngredientName;
};



#endif