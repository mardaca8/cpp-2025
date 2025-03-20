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
        string getBrand() const {
            return brand;
        }

        string getColor() const {
            return color;
        }
        
        int getYear() const {
            return year;
        }

        string getVin() const {
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
    const int size = 2;
    try {
        //static objects
        Vehicle car[size] = {
            Vehicle("Toyota", "Red", 2020, "1HGCM82633A123456"), 
            Vehicle("BMW", "Blue", 2018, "5YJSA1E26JF252345")
        };
        

        cout << "Initial objects state:" << endl;
        cout << car[0].toString() << endl;
        cout << car[1].toString() << endl;

        //setters
        car[0].setColor("Black");
        car[0].setYear(2022);
        car[0].setBrand("Mercedes");

        cout << "\nAfter state changes:" << endl;
        cout << car[1].toString() << endl;
        cout << car[1].toString() << endl;

        //dynamic objects
        Vehicle* cars[size] = {
            new Vehicle("Audi", "White", 2019, "1HGCM82633A123456"),
            new Vehicle("Ford", "Green", 2017, "5YJSA1E26JF252345")
        };

        cout << "\nDynamic objects state:" << endl;
        cout << cars[0]->toString() << endl;
        cout << cars[1]->toString() << endl;

        //counter
        cout << "\nTotal objects created: " << Vehicle::getObjectsCount() << endl;

        delete cars[0];
        //delete cars[1];

        cout << "\nAfter deleting dynamic objects:" << endl;
        cout << "Total objects remaining: " << Vehicle::getObjectsCount() << endl;
    }
    //cathing invalind vin and production year
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
