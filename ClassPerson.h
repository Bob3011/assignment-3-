#ifndef ClassPerson
#define ClassPerson

#include <iostream>
using namespace std;

class person
{
private:
	string name;
	int id;
	int age;


public:

	struct appointment
	{
		int  hrs;
		int mins;
	};

	person();

	void setName(string n);

	string getName();

	void setId(int num);

	int getId();

	void setAge(int num2);

	int getAge();

	virtual void printInfo();

};
#endif // ClassPerson