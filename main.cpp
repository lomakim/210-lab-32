// COMSC-210 | Lab 33 | Loma Kim
#include <iostream>
#include "car.h"
#include <deque>
#include <array>
using namespace std;
array<deque<Car>, 4> plaza;
deque<Car> tBooth;

void printLine(deque<Car>);
void printPlaza(deque<Car> []);

int main() {
    srand(time(0));
    const int SIZE = 2;
    Car t;              //temp Car object to hold info
    int probability;    //holds random probability percentage
    int opNum = 1;      //initialize operation count to 1
    int lane;           //holds lane number for switching

    // Cars initially in the toll booth plaza
    for (int i = 0; i < plaza.size(); i++) {
        for (int j = 0; j < SIZE; j++) {
            Car* temp = new Car;
            plaza[i].push_back(*temp);
            delete temp;
        }
    }


    // Print initial Queue
    cout << "Initial Queue: " << endl;
    for (int i = 0; i < plaza.size(); i++) {
        cout << "Lane " << i + 1 << ": " << endl;
        printLine(plaza[i]);
    }

    // Do-while loop randomly adds or removes car from queue and prints outcome
    for (int i = 0; i < 20; i++) {
        cout << "\nTime: " << opNum << endl;
        for (int j = 0; j < plaza.size(); j++) {
            cout << "Lane: " << j + 1 << " ";
            probability = (rand() % 100) + 1;

            // 46% probability the first car pays and leaves the line;
            if (probability <= 46) {
                t = plaza[j][0];
                cout << "Paid: ";
                t.print();
                plaza[j].pop_front();
            }
            // 39% probability a car joins the line for the toll booth
            else if(probability > 46 && probability < 86) {
                Car* temp = new Car;
                t = *temp;
                delete temp;
                cout << "Joined: ";
                t.print();
                plaza[j].push_back(t);
            }
            else {
                cout << "Switched: ";
                do {
                    lane = (rand() % 4);
                } while (lane == j);
                t = plaza[j][plaza[j].size() - 1];
                plaza[j].pop_back();
                plaza[lane].push_back(t);
                t.print();
            }
        }
        opNum++;                    // Increment operation counter
        cout << "Queue: " << endl;
        printLine(tBooth);
        cout << endl;

    }

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

void printPlaza(deque<Car> (&a)[]) {
    
}