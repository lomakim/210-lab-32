// COMSC-210 | Lab 33 | Loma Kim
#include <iostream>
#include "car.h"
#include <deque>
#include <array>
using namespace std;

array<deque<Car>, 4> arr;
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

    // Print initial Queue
    cout << "Initial Queue: " << endl;
    printLine(tBooth);
    cout << endl;

    // Do-while loop randomly adds or removes car from queue and prints outcome
    do {
        cout << "Time: " << opNum << " Operation: "; 
        probability = (rand() % 100) + 1;

        // 55% probability the first car pays and leaves the line;
        if (probability <= 55) {
            t = tBooth[0];
            cout << "Car paid: ";
            t.print();
            tBooth.pop_front();
        }
        // 45% probability a car joins the line for the toll booth
        else {
            Car* temp = new Car;
            t = *temp;
            delete temp;
            cout << "Joined lane: ";
            t.print();
            tBooth.push_back(t);
        }
        opNum++;                    // Increment operation counter
        cout << "Queue: " << endl;
        printLine(tBooth);
        cout << endl;

    } while (tBooth.empty() == false);

    return 0;
}

void printLine(deque<Car> t) {
    Car element;
    if (t.empty() == true)
        cout << "\tEmpty" << endl;
    else {
        for(int i = 0; i < t.size(); i++){
                element = t[i];
                cout << "\t";
                element.print();
        }
    }
}