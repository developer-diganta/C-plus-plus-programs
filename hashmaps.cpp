#include<iostream>
#include<cstring>
#include "hash.h"
using namespace std;


int main(){
	Hashtable<int> price_menu;

	price_menu.insert("Burger",120);
	price_menu.insert("Pepsi",12);
	price_menu.insert("Cola",14);
	price_menu.insert("Sauce",50);
	price_menu.insert("Food",500);
	price_menu.insert("Veggies",120);
	price_menu.insert("Cake",40);

	price_menu.print();
	int* find=price_menu.search("Peps");
	if(find!=NULL){
		cout<<"Price is "<<*find;
	}
	else
		cout<<"Not found";
	price_menu.erase("Food");
	price_menu.print();
	return 0;

}