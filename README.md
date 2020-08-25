# CoffeeMachine
Coffee Machine Simulator

Command to run:
```
g++ CoffeeMachine.cpp
./a.out
```
Output:
```
ginger_tea :
     hotWater : 500
     hotMilk : 100
     gingerSyrup : 40
     sugarSyrup : 30
     teaLeavesSyrup : 10

hot_tea :
     hotWater : 200
     hotMilk : 100
     gingerSyrup : 10
     sugarSyrup : 10
     teaLeavesSyrup : 10

elaichi_tea :
     hotWater : 200
     hotMilk : 100
     elaichiSyrup : 60
     sugarSyrup : 10
     teaLeavesSyrup : 10

hot_coffee :
     hotWater : 100
     hotMilk : 400
     sugarSyrup : 50
     coffeeSyrup : 20

espresso :
     hotWater : 200
     coffeeSyrup : 40

black_tea :
     hotWater : 300
     gingerSyrup : 30
     sugarSyrup : 50
     teaLeavesSyrup : 30

hot_milk :
     hotMilk : 200
     sugarSyrup : 30

green_tea :
     hotWater : 100
     gingerSyrup : 30
     greenMixture : 30
     
||  coffeeSyrup         ||  30       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  100      ||  
||  hotMilk             ||  500      ||  
||  hotWater            ||  500      ||  
||  sugarSyrup          ||  100      ||  
||  teaLeavesSyrup      ||  100      ||  

espresso cannot be prepared because coffeeSyrup is not sufficient
PASS
||  coffeeSyrup         ||  30       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  100      ||  
||  hotMilk             ||  500      ||  
||  hotWater            ||  500      ||  
||  sugarSyrup          ||  100      ||  
||  teaLeavesSyrup      ||  100      ||  

Refill coffeeSyrup with 20 units completed
PASS
||  coffeeSyrup         ||  50       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  100      ||  
||  hotMilk             ||  500      ||  
||  hotWater            ||  500      ||  
||  sugarSyrup          ||  100      ||  
||  teaLeavesSyrup      ||  100      ||  

ginger_tea is prepared
PASS
||  coffeeSyrup         ||  50       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  60       ||  
||  hotMilk             ||  400      ||  
||  hotWater            ||  0        ||  (LOW) 
||  sugarSyrup          ||  70       ||  
||  teaLeavesSyrup      ||  90       ||  

Refill hotWater with 600 units completed
Refill hotMilk with 100 units completed
PASS
||  coffeeSyrup         ||  50       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  60       ||  
||  hotMilk             ||  500      ||  
||  hotWater            ||  600      ||  
||  sugarSyrup          ||  70       ||  
||  teaLeavesSyrup      ||  90       ||  

||  coffeeSyrup         ||  30       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  100      ||  
||  hotMilk             ||  500      ||  
||  hotWater            ||  500      ||  
||  sugarSyrup          ||  100      ||  
||  teaLeavesSyrup      ||  100      ||  

espresso cannot be prepared because coffeeSyrup is not sufficient
PASS
||  coffeeSyrup         ||  30       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  100      ||  
||  hotMilk             ||  500      ||  
||  hotWater            ||  500      ||  
||  sugarSyrup          ||  100      ||  
||  teaLeavesSyrup      ||  100      ||  

Refill coffeeSyrup with 20 units completed
PASS
||  coffeeSyrup         ||  50       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  100      ||  
||  hotMilk             ||  500      ||  
||  hotWater            ||  500      ||  
||  sugarSyrup          ||  100      ||  
||  teaLeavesSyrup      ||  100      ||  

ginger_tea is prepared
PASS
||  coffeeSyrup         ||  50       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  60       ||  
||  hotMilk             ||  400      ||  
||  hotWater            ||  0        ||  (LOW) 
||  sugarSyrup          ||  70       ||  
||  teaLeavesSyrup      ||  90       ||  

Refill hotWater with 600 units completed
Refill hotMilk with 100 units completed
PASS
||  coffeeSyrup         ||  50       ||  
||  elaichiSyrup        ||  100      ||  
||  gingerSyrup         ||  60       ||  
||  hotMilk             ||  500      ||  
||  hotWater            ||  600      ||  
||  sugarSyrup          ||  70       ||  
||  teaLeavesSyrup      ||  90       ||  


```
