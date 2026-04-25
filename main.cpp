// COMSC-210 | Lab 32 | Loma Kim
#include <iostream>
#include "car.h"
#include <deque>
using namespace std;
deque<Car> tBooth;

void printLine(deque<Car>);

int main() {
    srand(time(0));
    const int SIZE = 2;
    Car t;
    int probability;    //holds random probability percentage
    int opNum = 1;      //initialize operation count to 1

    // Cars initially in the toll booth line
    for (int i = 0; i < SIZE; i++) {
        Car* temp = new Car;
        tBooth.push_back(*temp);
        delete temp;
    }
    cout << "Initial Queue: " << endl;
    printLine(tBooth);

    do {
        cout << "Time: " << opNum << "Operation: "; 
        probability = (rand() % 100) + 1;
        // 55% probability the first car pays and leaves the line;
        if (probability <= 55) {
            t = tBooth[0];
            cout << "Car paid: ";
            t.print();
            cout << endl;
            tBooth.pop_front();
        }
        else {
            Car* temp = new Car;
            t = *temp;
            cout << "Joined lane: ";
            t.print();
            cout << endl;
            tBooth.push_back(t);


        }

    } while (tBooth.empty() == false);

    return 0;
}

void printLine(deque<Car> t) {
    Car element;
    for(int i = 0; i < t.size(); i++){
            element = t[i];
            cout << "\t";
            element.print();
    }
}