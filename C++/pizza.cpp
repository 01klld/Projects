#include <iostream>
using namespace std;

void MakingCheckenPizza(){
   cout << "Making Checken pizza base" << endl;
   cout << "Adding Checken toppings" << endl;
   cout << "Baking Checken pizza" << endl;
}

void MakingBeefPizza(){
   cout << "Making beef pizza base" << endl;
   cout << "Adding beef toppings" << endl;
   cout << "Baking beef pizza" << endl;
}

void MakingCheesePizza(){
   cout << "Making Cheese pizza base" << endl;
   cout << "Adding Cheese toppings" << endl;
   cout << "Baking Cheese pizza" << endl;
}

int main()
{
   int choice;
   cout << "Please Choice Your Pizza (1 for beef, 2 for cheese, 3 for checken)" << endl;
   cin >> choice;
   switch(choice)
   {
    case 1 :
         MakingBeefPizza();
         break;
    case 2 :
         MakingCheesePizza();
         break;
    case 3 :
         MakingCheckenPizza();
         break;
    default :
        cout << "Invalid Choice" << endl;
   }
}