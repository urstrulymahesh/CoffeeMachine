#ifndef TestCases_H
#define TestCases_H

#include "CoffeeMachine.h"
#include<cassert>
#include <iostream>
#include "utils.h"
using namespace std;

void TestRefill(CoffeeMachine& machine) {
	machine.RefillIngredients(vector<Ingredient>({ Ingredient("coffeeSyrup",20) }));
	assert(machine.Stock["coffeeSyrup"] == 50);
	cout << "PASS" << endl;
	DisplayInventory(machine);
}

void TestSuccessfulDispension(CoffeeMachine & machine) {
	Beverage ginger_tea = machine.DispenseBeverage("ginger_tea");
	assert(machine.Stock["hotWater"] == 0);
	assert(machine.Stock["hotMilk"] == 400);
	assert(machine.Stock["gingerSyrup"] == 60);
	assert(machine.Stock["sugarSyrup"] == 70);
	assert(machine.Stock["teaLeavesSyrup"] == 90);
	cout << "PASS" << endl;
	DisplayInventory(machine);
}

void TestRefillMultiple(CoffeeMachine & machine) {
	machine.RefillIngredients(vector<Ingredient>({ Ingredient("hotWater",600),Ingredient("hotMilk",100) }));
	assert(machine.Stock["hotWater"] == 600);
	assert(machine.Stock["hotMilk"] == 500);
	cout << "PASS" << endl;
	DisplayInventory(machine);
}

void TestMultipleDispensions(CoffeeMachine & machine) {
	Beverage hot_tea = machine.DispenseBeverage("hot_tea");
	Beverage hot_coffee = machine.DispenseBeverage("hot_coffee");
	Beverage green_tea = machine.DispenseBeverage("green_tea");
	Beverage black_tea = machine.DispenseBeverage("black_tea");
	assert(machine.Stock["hotWater"] == 300);
	assert(machine.Stock["hotMilk"] == 0);
	assert(machine.Stock["coffeeSyrup"] == 30);
	assert(machine.Stock["gingerSyrup"] == 50);
	assert(machine.Stock["sugarSyrup"] == 10);
	assert(machine.Stock["teaLeavesSyrup"] == 80);
	cout << "PASS" << endl;
	DisplayInventory(machine);
}

void TestInsufficientIngredientQuantity(CoffeeMachine& machine) {
	Beverage espresso = machine.DispenseBeverage("espresso");
	assert(machine.Stock["coffeeSyrup"] == 30);
	cout << "PASS" << endl;
	DisplayInventory(machine);
}

void TestIngredientNotAvailable(CoffeeMachine& machine) {
	Beverage green_tea = machine.DispenseBeverage("green_tea");
	cout << "PASS" << endl;
	DisplayInventory(machine);
}

void TestRefillNewIngredient(CoffeeMachine& machine) {
	machine.RefillIngredients(vector<Ingredient>({ Ingredient("greenMixture",40) }));
	assert(machine.Stock["greenMixture"] == 40);
	cout << "PASS" << endl;
	DisplayInventory(machine);
}



#endif
