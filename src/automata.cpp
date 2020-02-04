#include "Automata.h"
#include <iostream>
using namespace std;
Automata::Automata() {
	string* menu = new string[1];
	int* prices = new int[1];
	menu[0] = "drink";
	prices[0] = 10;
	this->menu = menu;
	this->prices = prices;
	this->length = 1;
	this->cash = 0;
	state = OFF;
}
Automata::Automata(string* menu, int* prices, int length) {
	this->menu = menu;
	this->prices = prices;
	this->length = length;
	menu = NULL;
	prices = NULL;
	this->cash = 0;
	state = OFF;	   	 
}
void Automata::on() {
	if (state == OFF) {
		state = WAIT;
	}
}
void Automata::off() {
	if (state == WAIT) {
		state = OFF;
	}
}
void Automata::coin(int money) {
	if (state == WAIT) {
		cash = money;
		state = ACCEPT;
	}
	else {
		if (state == ACCEPT) {
			cash += money;
		}
	}

}
int Automata::cancel() {
	int buf;
	if (state == ACCEPT) {
		state = WAIT;
		buf = cash;
		cash = 0;
		return buf;
	}
	else {
		if (state == CHECK) {
			state = ACCEPT;
		}
	}
	return -1;
}
void Automata::choice() {
	if (state == ACCEPT) {
		state = CHECK;
	}
}
int Automata::check(int number) {
	if (state == CHECK) {
		number--;
		if (number >= length) {
			return 1;
		}
		else {
			if (cash >= prices[number]) {
				return 0;
			}
			else {
				return 1;
			}
			
		}
	}
	return 1;
}
void Automata::cook(int number, void (*prod)(int )) {
	if (state == CHECK) {
		state = COOK;
		(*prod)(number);
	}
}
int Automata::finish() {
	int buf;
	if (state == COOK) {
		state = WAIT;
		buf = cash;
		cash = 0;
		return buf;
	}
	return -1;
}
string Automata::getMenu() {
	string str;
	if (length != 0) {
		str = menu[0] + " " + to_string(prices[0]) + "\n";
		for (int i = 1; i < length; i++) {
			str += menu[i] + " " + to_string(prices[i]) + "\n";
		}
	}
	else {
		str = "No drinks";
	}
	return str;
}
STATE Automata::getState() {
	return state;
}
/////
void Automata::cook() {
	int a = 10;
}