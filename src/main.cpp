#define _CRT_SECURE_NO_WARNINGS
#include "Automata.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
void prod(int number) {
	cout << number << ":" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "|";
	}
	cout << "\n";
}
int main() {
	/*
	File format:
	3
	drink1 10
	drink2 20
	drink3 30
	*/
	FILE* fp = fopen("menu.txt", "r");
	int amount, price;
	char buf[20];
	fscanf(fp, "%d\n", &amount);
	int* prices = new int[amount];
	string* menu = new string[amount];
	for (int i = 0; i < amount; i++) {
		fscanf(fp, "%s%d\n", buf, &price);
		prices[i] = price;
		menu[i] = string(buf);
	}
	Automata A;
	int money_in = 15, number = 1;
	//script
	A.on();
	A.coin(money_in);
	A.choice();
	cout << A.getMenu();
	if (A.check(2) == 0) {
		A.cook(number, prod);
	}
	else {
		A.cancel();
		A.coin(20);
		A.choice();
		A.cook(number, prod);
	}
	A.finish();
	A.off();
	cout << A.getState() << endl;
	//endscript
	fclose(fp);
	return 0;
}