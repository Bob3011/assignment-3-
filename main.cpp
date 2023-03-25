#include <iostream>
#include "ClassCustomer.h"
#include "ClassMechanic.h"
#include "ClassTempQueue.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;


int main()
{
    //Queue<mechanic> mechanicsQueue;
    Queue<mechanic> mechanicsQueue;

    mechanic* mech = new mechanic[1]; // allocate memory for the new customer array
    int mechNum = 0; // initialize the counter for the size of the customer array
    int appNum;

    //to enter mechanic information from a file to a dinamic array
    ifstream mechanics;
    mechanics.open("mechanics.txt");

    if (mechanics.fail())
    {
        cout << "there was an error while opening this file" << endl;
        exit(1);
    }
    else
    {
        string name;
        int age;
        int id;
        int hrs;
        int mins;

        mechanic* temp = NULL;

        while (getline(mechanics, name))
        {
            // set new customer
            temp = new mechanic[mechNum + 1];

            // copy the existing customers to the new memory block
            for (int i = 0; i < mechNum; i++)
            {
                *(temp + i) = *(mech + i);
            }

            // read in the new customer data
            mechanics >> id;
            mechanics >> age;
            mechanics >> appNum;

            (temp + mechNum)->setName(name);
            (temp + mechNum)->setAge(age);
            (temp + mechNum)->setId(id);
            (temp + mechNum)->setCounter(appNum);

            for (int i = 0; i < (temp + mechNum)->getCounter(); i++)
            {
                mechanics >> hrs;
                mechanics >> mins;

                (temp + mechNum)->setApp(hrs, mins, i);
            }

            mechNum++; // increment the size of the customer array

            // update the pointer
            delete[] mech;
            mech = temp;
            temp = nullptr;
            mechanics.ignore(1000, '\n'); // skip to the next line
        }
    }

    for (int i = 0; i < mechNum; i++)
    {
        mechanicsQueue.enqueue(*(mech + i));
    }

    //test loop
    /*for (int i = 0; i < mechNum; i++)
    {
        (mech + i)->printInfo();
    }*/



    customer* cust = new customer[1]; // allocate memory for the new customer array
    int custNum = 0; // initialize the counter for the size of the customer array

    //to inpu tcustomer information from files to a dinamics array 
    ifstream customers;
    customers.open("Customer.txt");

    if (customers.fail())
    {
        cout << "there was an error while opening this file" << endl;
        exit(1);
    }
    else
    {
        string name;
        int age;
        int id;
        int hrs;
        int mins;
        customer* temp = NULL;

        while (getline(customers, name))
        {
            // set new customer
            temp = new customer[custNum + 1];

            // copy the existing customers to the new memory block
            for (int i = 0; i < custNum; i++)
            {
                *(temp + i) = *(cust + i);
            }

            // read in the new customer data
            customers >> id;
            customers >> age;
            (temp + custNum)->setName(name);
            (temp + custNum)->setAge(age);
            (temp + custNum)->setId(id);

            customers >> hrs;
            customers >> mins;
            (temp + custNum)->setApp(hrs, mins);

            custNum++; // increment the size of the customer array

            // update the pointer
            delete[] cust;
            cust = temp;
            temp = nullptr;
            customers.ignore(1000, '\n'); // skip to the next line
        }
    }

    /*for (int i = 0; i < custNum; i++)
    {
        (cust + i)->printInfo();
    }
    cout << endl;*/

    Queue<customer> customerQueue;

    // to assign a cutomer to a mechanic using an isAvailable function
    int z = 0;
    for (int i = 0; i < custNum; i++)
    {
        if (i >= mechNum)
        {
            if ((mech+z)->isAvailable((cust + i)->getHrs(), (cust + i)->getMins() )==1)
            {
                (cust + i)->setMechanicId((mech+i)->getId());
                (cust + i)->setMechanicName((mech+i)->getName());
                z++;
            }
            else
            {
                if ((mech + (z + 1))->isAvailable((cust + i)->getHrs(), (cust + i)->getMins()) == 1)
                {
                    (cust + i)->setMechanicId((mech + (z + 1))->getId());
                    (cust + i)->setMechanicName((mech + (z + 1))->getName());
                    z++;
                }
            }
        }
        else
        {
            if ((mech + i)->isAvailable((cust + i)->getHrs(), (cust + i)->getMins()) == 1)
            {
                (cust + i)->setMechanicId((mech + i)->getId());
                (cust + i)->setMechanicName((mech + i)->getName());
            }
            else
            {
                cout << "there are no available appointment for"<< (cust+i)->getName()<< endl;
            }
        }
    }

    
    // sort the dinamic array of customers
    customer cTemp;
    for (int i = 0; i < custNum - 1; i++)
    {
        for (int j = 0; j < custNum - i - 1; j++) 
        {
            if (*(cust + j) < *(cust + (j + 1)))
            {
                //swap arr[j] and arr[j+1]
                 cTemp = *(cust+j);
                *(cust+j) = *(cust+ (j+1));
                *(cust+ (j+1)) = cTemp;
            }
        }
    }

    //enqueue the dinamic array of customers the queue
    for (int i = 0; i < custNum; i++)
    {
        customerQueue.enqueue(*(cust + i));
    }

    // print out the customer information by dequeueing from the queue
    for (int i = 0; i < custNum; i++)
    {
        customerQueue.dequeue().printInfo();
    }

    delete[] cust;
    delete[] mech;

    return 0;
}