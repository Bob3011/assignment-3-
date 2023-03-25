#include <iostream>
#include "ClassMechanic.h"
using namespace std;

mechanic:: mechanic()
{
	counter = NULL;
	m = nullptr;
}

void mechanic::setCounter(int num)
{
	counter = num;
	m = new appointment[counter];
}

int mechanic::getCounter()
{
	return counter;
}

void mechanic::setApp(int num, int num2, int index)
{
	(m + index)->hrs = num;
	(m + index)->mins = num2;
}

int mechanic::getAppHrs()
{
	return m->hrs;
}

int mechanic::getAppMins()
{
	return m->mins;
}

bool mechanic::isAvailable(int hours, int min)	//  function is alailable checks if hrs and mins are found in the array if no
{												// then it append a the array by making use of a temp array
	int x = 1;

	for (int i = 0; i < counter; i++)
	{
		if ((m + i)->hrs == hours && (m + i)->mins == min)
		{
			x = 0;
		}
		else
		{
			continue;
		}
	}
	if (x == 1)
	{
		appointment* temp = new appointment[counter + 1];
		for (int i = 0; i < counter; i++)
		{
			*(temp + i) = *(m + i);
		}
		temp[counter].hrs = hours;
		temp[counter].mins = min;
		counter++;
		delete[] m;
		m = temp;
	}

	return x;
}

void mechanic::printInfo()					// print info in mechanics mainly used to check for errors in out put
{
	cout << "Name: " << this->getName() << endl;
	cout << "Age: " << this->getAge() << endl;
	cout << "Id: " << this->getId() << endl;
	cout << "appointments: " << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << "hrs: " << (m + i)->hrs << endl;
		cout << "mins: " << (m + i)->mins << endl;
	}
	cout << endl;
}