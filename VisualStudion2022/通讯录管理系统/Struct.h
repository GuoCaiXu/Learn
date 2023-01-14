# include <iostream>
using namespace std;
# include <string>

#ifndef HERO_H
#define HERO_H

struct A {

	string name;
	string number;
	string Address;
};

struct Person {

	A Data[1000];
	int Quantity = 0;
};

#endif
