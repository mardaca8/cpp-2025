#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

class Vehicle {
    private:
        string brand;
        string color;
        int year;
        string vin;

        static int objectsCount;

    public:
        //constructor
        Vehicle(string brand, string color, int year, string vin) {
            setBrand(brand);
            setColor(color);
            setYear(year);
            setVin(vin);
            objectsCount++;
        }

        //destructor
        ~Vehicle() {
            objectsCount--;
        }

        //getters
        string getBrand() {
            return brand;
        }

        string getColor() {
            return color;
        }
        
        int getYear() {
            return year;
        }

        string getVin() {
            return vin;
        }

        static int getObjectsCount() {
            return objectsCount;
        }

        //setters
        void setBrand(string brand) {
            this->brand = brand;
        }

        void setColor(string color) {
            this->color = color;
        }

        void setYear(int year) {
            if (year < 1900 || year > 2025) {
                throw invalid_argument("Invalid production year");
            }
            this->year = year;
        }

        void setVin(string vin) {
            if (vin.length() != 17) {
                throw invalid_argument("Invalid VIN number");
            }
            this->vin = vin;
        }

        string toString() {
            stringstream output;
            output << "Brand: " << brand << " | Color: " << color << " | Year: " << year << " | VIN: " << vin;
            return output.str();
        }
};

int Vehicle::objectsCount = 0;

int main() {
    Vehicle* vehicle[5];

    assert(Vehicle::getObjectsCount() == 0);
    vehicle[0] = new Vehicle("Audi", "Black", 2010, "W23A56D89W12G45FG");
    vehicle[1] = new Vehicle("BMW", "White", 2015, "W23A56D89W12G45FG");
    vehicle[2] = new Vehicle("Mercedes", "Red", 2018, "W23A56D89W12G45FG");
    vehicle[3] = new Vehicle("Toyota", "Blue", 2019, "W23A56D89W12G45FG");
    vehicle[4] = new Vehicle("Ford", "Green", 2020, "W23A56D89W12G45FG");
    assert(Vehicle::getObjectsCount() == 5);

    //initialization 
    assert(vehicle[0]->getBrand() == "Audi");
    assert(vehicle[0]->getColor() == "Black");
    assert(vehicle[0]->getYear() == 2010);
    assert(vehicle[0]->getVin() == "W23A56D89W12G45FG");

    assert(vehicle[2]->getBrand() == "Mercedes");
    assert(vehicle[2]->getColor() == "Red");
    assert(vehicle[2]->getYear() == 2018);
    assert(vehicle[2]->getVin() == "W23A56D89W12G45FG");

    //setters
    vehicle[0]->setBrand("Audi 100");
    vehicle[0]->setColor("Black night");
    vehicle[0]->setYear(2025);
    vehicle[0]->setVin("WWWWWWWWWWWWWWWWW");

    assert(vehicle[0]->getBrand() == "Audi 100");
    assert(vehicle[0]->getColor() == "Black night");
    assert(vehicle[0]->getYear() == 2025);
    assert(vehicle[0]->getVin() == "WWWWWWWWWWWWWWWWW");

    vehicle[0]->setColor("Black sky");
    assert(vehicle[0]->getColor() == "Black sky");


    assert(Vehicle::getObjectsCount() == 5);
    for (int i = 4; i >= 0; i--) {  
        cout << vehicle[i]->toString() << endl;
        delete vehicle[i];
        assert(Vehicle::getObjectsCount() == i);
    }

    assert(Vehicle::getObjectsCount() == 0);

    return 0;
}
