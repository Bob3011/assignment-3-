#ifndef ClassCutomer
#define ClassCustomer

#include <iostream>
//#include "StructApp.h"
#include "ClassPerson.h"
using namespace std;

class customer : public person
{
private:
	int mechanicId;
	string mechanicName;
	appointment c;

public:
	customer();

	void setMechanicId(int num);

	int getmechanicID();

	void setMechanicName(string n);

	string getMechanicName();

	void setApp(int num2, int num3);

	int getHrs();

	int getMins();

	bool operator < (customer& customer);

	bool operator > (customer& customer);

	bool operator == (customer& customer);

	void printInfo();
};

#endif