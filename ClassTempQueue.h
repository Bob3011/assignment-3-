#ifndef ClassTempQueue
#define ClassTempQueue

#include <iostream>
using namespace std;

template <class T>
class Queue {
public:
    Queue()
    {
        int size = 10;
        values = new T[size];
        maxSize = size;
        front = 0;
        rear = -1;
        counter = 0;

    }
    ~Queue() { delete[] values; }

    bool isEmpty(void)
    {
        if (counter != 0)
            return false;
        else
            return true;
    }

    bool isFull(void)
    {
        if (counter < maxSize)
            return false;
        else
            return true;
    }
    bool enqueue(T& x)
    {
        if (isFull()) {
            cout << "Error: the queue is full." << endl;
            return false;
        }
        else {
            rear = (rear + 1) % maxSize;

            values[rear] = x;
            counter++;
            return true;
        }
    }
    T dequeue()
    {
        if (isEmpty()) {
            exit(EXIT_FAILURE);
        }
        else {
            T y;
            y = values[front];
            front = (front + 1) % maxSize;
            counter--;
            return y;
        }

    }


private:
    int front;
    int rear;
    int counter;
    int maxSize;
    T* values;
};
#endif //ClassTempQueue
