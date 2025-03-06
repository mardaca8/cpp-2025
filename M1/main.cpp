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
        int id;

        static int idCounter;
        static int objectsCount;

    public:
        //constructor
        Vehicle(string brand) {
            setBrand(brand);
        }

        Vehicle(string brand, string color, int year, string vin) {
            setBrand(brand);
            setColor(color);
            setYear(year);
            setVin(vin);
            setId(idCounter);
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

        void setId(int id) {
            this->id = id;
            idCounter++;
        }

        string toString() {
            stringstream output;
            output << "Brand: " << brand << " | Color: " << color << " | Year: " << year << " | VIN: " << vin << " | ID: " << id;
            return output.str();
        }
};

//intialize static variables
int Vehicle::objectsCount = 0;
int Vehicle::idCounter = 1;

int main() {
    try {
        //static objects
        Vehicle car1("Toyota", "Red", 2020, "1HGCM82633A123456");
        Vehicle car2("BMW", "Blue", 2018, "5YJSA1E26JF252345");

        cout << "Initial objects state:" << endl;
        cout << car1.toString() << endl;
        cout << car2.toString() << endl;

        //setters
        car1.setColor("Black");
        car1.setYear(2022);
        car2.setBrand("Mercedes");

        cout << "\nAfter state changes:" << endl;
        cout << car1.toString() << endl;
        cout << car2.toString() << endl;

        //dynamic objects
        Vehicle* car3 = new Vehicle("Audi", "White", 2021, "WAUZFAFC9JN123456");
        Vehicle* car4 = new Vehicle("Ford", "Grey", 1924, "1FAFP4448YF123456");

        cout << "\nDynamic objects state:" << endl;
        cout << car3->toString() << endl;
        cout << car4->toString() << endl;

        //counter
        cout << "\nTotal objects created: " << Vehicle::getObjectsCount() << endl;

        delete car3;
        delete car4;

        cout << "\nAfter deleting dynamic objects:" << endl;
        cout << "Total objects remaining: " << Vehicle::getObjectsCount() << endl;
    }
    //cathing invalind vin and production year
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
