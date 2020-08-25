#ifndef IngredientNotAvailableException_H
#define IngredientNotAvailableException_H

#include<string>
using namespace std;

//Exception class for Ingredient not available case
class IngredientNotAvailableException {
public:
	IngredientNotAvailableException(string BeverageName, string IngredientName) {
		this->BeverageName = BeverageName;
		this->IngredientName = IngredientName;
	}

	string what() {
		return BeverageName + " cannot be prepared because " + IngredientName + " is not available";
	}

private:
	string BeverageName;
	string IngredientName;
};



#endif