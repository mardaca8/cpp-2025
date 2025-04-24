#include <iostream>
#include <fstream>
#include "Vehicle.h"
#include "Engine.h"

using namespace std;

int main() {
    const int size = 3;
    //dynamic objects
    cout << "\nDynamic objects state:" << endl;

    //array of objects
    Vehicle* cars2 = new Vehicle[size];
    cars2[0] = Vehicle("Audi", "White", 2019, "1HGCM82633A123456");
    cars2[1] = Vehicle("Ford", "Green", 2017, "5YJSA1E26JF252345");
    cars2[1].setEngine(new DieselEngine());
    cars2[2] = Vehicle("Tesla", "White", 2020, "5YJSA1E26JF252345");
    cars2[2].setEngine(new ElectricEngine());

    //print dynamic objects
    for(int i = 0; i < size; i++) {
        cout << cars2[i].toString() << endl;
    }

    //switch engine
    cars2[0].switchEngine(1);
    cout << "\nAfter switching engine:" << endl;

    for(int i = 0; i < size; i++) {
        cout << cars2[i].toString() << endl;
    }


    std::ofstream ofs("vehicle.dat", std::ios::binary);
    for(int i = 0; i < size; i++) {
        ofs << cars2[i];
    }
    ofs.close();

    Vehicle* loaded = new Vehicle[size];
    std::ifstream ifs("vehicle.dat", std::ios::binary);
    for (int i = 0; i < size; i++) {
        ifs >> loaded[i];
    }
    ifs.close();

    for(int i = 0; i < size; i++) {
        cout << "LOADED:" << loaded[i].toString() << endl;
    }

    //counter
    cout << "\nTotal objects created: " << Vehicle::getObjectsCount() << endl;

    // //delete dynamic objects
    // delete[] cars2;

    // cout << "\nAfter deleting dynamic objects:" << endl;
    // cout << "Total objects remaining: " << Vehicle::getObjectsCount() << endl;

    return 0;
}
