#ifndef ClassMechanic
#define ClassMechanic

#include <iostream>
#include "ClassPerson.h"
//#include "StructApp.h"
using namespace std;

class mechanic : public person
{
private:
	int counter;
	appointment* m;

public:
	mechanic();

	void setCounter(int num);

	int getCounter();

	void setApp(int num, int num2, int index);

	int getAppHrs();

	int getAppMins();

	bool isAvailable(int hours, int min);

	void printInfo();

};

#endif