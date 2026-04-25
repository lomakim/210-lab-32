// COMSC-210 | Lab 32 | Loma Kim
#include <iostream>
#include "car.h"
#include <deque>
using namespace std;
deque<Car> tBooth;

int main() {
    srand(time(0));
    const int SIZE = 2;
    Car element;

    // Cars initially in the toll booth line
    Car t1, t2;
    tBooth.push_back(t1);
    tBooth.push_back(t2);

    for(int i = 0; i < tBooth.size(); i++){
        element = tBooth[i];
        element.print();
    }
    
    return 0;
}