#include <iostream>
#include "ClassPerson.h"
using namespace std;

struct appointment
{
	int  hrs;
	int mins;
};

person::person()
{
	name = "noName";
	id = 0000;
	age = 00;
}

void person::setName(string n)
{
	name = n;
}

string person::getName()
{
	return name;
}

void person::setId(int num)
{
	id = num;
}

int person::getId()
{
	return id;
}

void person::setAge(int num2)
{
	age = num2;
}

int person::getAge()
{
	return age;
}

void person::printInfo()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Id: " << id << endl;
}
