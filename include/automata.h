#pragma once
#include <string>
using namespace std;
enum STATE {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};
class Automata {
public:
	Automata();
	Automata(string* menu, int* prices, int length);
	void on();
	void off();
	void coin(int money);
	string getMenu();
	STATE getState();
	void choice();
	int cancel();
	int check(int number);
	void cook(int number, void (*prod)(int ));
	void cook();
	int finish();
private:
	int cash;
	string* menu;
	int* prices;
	int length;
	STATE state;
};