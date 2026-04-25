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
    int probability;

    // Cars initially in the toll booth line
    for (int i = 0; i < SIZE; i++) {
        Car* temp = new Car;
        tBooth.push_back(*temp);
    }


    printLine(tBooth);

    do {
        probability = (rand() % 100) + 1;
        if (probability <= 55) {

        }
    } while (tBooth.empty() == false);

    return 0;
}

void printLine(deque<Car> t) {
    Car element;
    for(int i = 0; i < t.size(); i++){
            element = t[i];
            element.print();
    }
}