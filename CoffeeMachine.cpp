

#include <iostream>
using namespace std;
#include <vector>
#include<string>
#include<map>
#include<exception>
#include<mutex>
#include<cassert>
#include <iomanip>

#include"Ingredient.h"
#include"Beverage.h"
#include "CoffeeMachine.h"
#include "TestCases.h"
#include "utils.h"

int main()
{	
	vector<Ingredient> Stock;
	Stock.push_back(Ingredient("hotWater", 500));
	Stock.push_back(Ingredient("hotMilk", 500));
	Stock.push_back(Ingredient("gingerSyrup", 100));
	Stock.push_back(Ingredient("sugarSyrup", 100));
	Stock.push_back(Ingredient("teaLeavesSyrup", 100));
	Stock.push_back(Ingredient("coffeeSyrup", 30));
	Stock.push_back(Ingredient("elaichiSyrup", 100));

	vector<Beverage>beverages;
	beverages.push_back(Beverage("ginger_tea", vector<Ingredient>{Ingredient("hotWater", 500), Ingredient("hotMilk", 100), Ingredient("gingerSyrup", 40), Ingredient("sugarSyrup", 30), Ingredient("teaLeavesSyrup", 10)}));
	beverages.push_back(Beverage("hot_tea", vector<Ingredient>{Ingredient("hotWater", 200), Ingredient("hotMilk", 100), Ingredient("gingerSyrup", 10), Ingredient("sugarSyrup", 10), Ingredient("teaLeavesSyrup", 10)}));
	beverages.push_back(Beverage("elaichi_tea", vector<Ingredient>{Ingredient("hotWater", 200), Ingredient("hotMilk", 100), Ingredient("elaichiSyrup", 60), Ingredient("sugarSyrup", 10), Ingredient("teaLeavesSyrup", 10)}));
	beverages.push_back(Beverage("hot_coffee", vector<Ingredient>{Ingredient("hotWater", 100), Ingredient("hotMilk", 400), Ingredient("sugarSyrup", 50), Ingredient("coffeeSyrup", 20)}));
	beverages.push_back(Beverage("espresso", vector<Ingredient>{Ingredient("hotWater", 200), Ingredient("coffeeSyrup", 40)}));
	beverages.push_back(Beverage("black_tea", vector<Ingredient>{Ingredient("hotWater", 300), Ingredient("gingerSyrup", 30), Ingredient("sugarSyrup", 50), Ingredient("teaLeavesSyrup", 30)}));
	beverages.push_back(Beverage("hot_milk", vector<Ingredient>{Ingredient("hotMilk", 200), Ingredient("sugarSyrup", 30)}));
	beverages.push_back(Beverage("green_tea", vector<Ingredient>{Ingredient("hotWater", 100), Ingredient("gingerSyrup", 30), Ingredient("greenMixture", 30)}));

	CoffeeMachine machine(3, Stock, beverages);
	DisplayBeverage(beverages);
	DisplayInventory(machine);

	//TestSuite
	TestInsufficientIngredientQuantity(machine);
	TestRefill(machine);
	TestSuccessfulDispension(machine);
	TestRefillMultiple(machine);
	TestMultipleDispensions(machine);
	TestIngredientNotAvailable(machine);
	TestRefillNewIngredient(machine);
	TestIngredientNotAvailable(machine);
}

