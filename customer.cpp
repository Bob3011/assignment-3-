#include "ClassCustomer.h"
using namespace std;

customer::customer()
{
	mechanicName = "noName";
	mechanicId = 0;
	c.hrs = 0;
	c.mins = 0;
}

void customer::setMechanicId(int num)
{
	mechanicId = num;
}

int customer::getmechanicID()
{
	return mechanicId;
}

void customer::setMechanicName(string n)
{
	mechanicName = n;
}

string customer::getMechanicName()
{
	return mechanicName;
}

void customer::setApp(int num2, int num3)
{
	c.hrs = num2;
	c.mins = num3;
}

int customer::getHrs()
{
	return c.hrs;
}

int customer::getMins()
{
	return c.mins;
}

bool customer::operator < (customer& n)
{
	bool ans = true;
	if (this->c.hrs < n.c.hrs)
	{
		ans = true;
	}
	else if (this->c.hrs == n.c.hrs)
	{
		if (this->c.mins < n.c.mins)
		{
			ans = true;
			return ans;
		}
		else
		{
			ans = false;
			return ans;
		}
	}
	return ans;
}

void customer::printInfo()
{
	cout << (this)->getName() << " hass appointmnet at " << (this)->getHrs() << ":" << (this)->getMins() << "0 with " << this->getMechanicName() << " of  id " << this->getmechanicID() << endl;
}