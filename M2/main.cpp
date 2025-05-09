#include <iostream>
#include <fstream>
#include "Vehicle.h"

using namespace std;

int main() {
    const int size = 2;
    //dynamic objects
    cout << "\nDynamic objects state:" << endl;

    //array of objects
    Vehicle* cars2 = new Vehicle[size];
    cars2[0] = Vehicle("Audi", "White", 2019, "1HGCM82633A123456");
    cars2[1] = Vehicle("Ford", "Green", 2017, "5YJSA1E26JF252345");
    

    //print dynamic objects
    for(int i = 0; i < size; i++) {
        cout << cars2[i].toString() << endl;
    }

    //counter
    cout << "\nTotal objects created: " << Vehicle::getObjectsCount() << endl;

    //delete dynamic objects
    delete[] cars2;

    cout << "\nAfter deleting dynamic objects:" << endl;
    cout << "Total objects remaining: " << Vehicle::getObjectsCount() << endl;

    return 0;
}
