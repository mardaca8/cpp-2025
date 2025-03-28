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

        //default constructor
        Vehicle() {
            setBrand("Unknown");
            setColor("Unknown");
            setYear(2000);
            setVin("XXXXXXXXXXXXXXXXX");
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
            if (year < 1900 || year >= 2025) {
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

        string toString() const {
            stringstream output;
            output << "Brand: " << brand << " | Color: " << color << " | Year: " << year << " | VIN: " << vin << " | ID: " << id;
            return output.str();
        }

        private:
            void setId(int id) {
                this->id = id;
                idCounter++;
            }
};

//intialize static variables
int Vehicle::objectsCount = 0;
int Vehicle::idCounter = 1;

int main() {
    const int size = 2;
    try {
        //static objects
        Vehicle cars[size] = {
            Vehicle("Toyota", "Red", 2020, "1HGCM82633A123456"), 
            Vehicle("BMW", "Blue", 2018, "5YJSA1E26JF252345")
        };
        
        cout << "Initial objects state:" << endl;
        cout << cars[0].toString() << endl;
        cout << cars[1].toString() << endl;

        //setters
        cars[0].setColor("Black");
        cars[0].setYear(2022);
        cars[0].setBrand("Mercedes");

        cout << "\nAfter state changes:" << endl;
        cout << cars[0].toString() << endl;
        cout << cars[1].toString() << endl;

        //dynamic objects
        cout << "\nDynamic objects state:" << endl;

        //array of pointers
        Vehicle* cars1[size] = {
            new Vehicle("Audi", "White", 2019, "1HGCM82633A123456"),
            new Vehicle("Ford", "Green", 2017, "5YJSA1E26JF252345")
        };

        //array of objects
        Vehicle* cars2 = new Vehicle[size];
        cars2[0] = Vehicle("Audi", "White", 2019, "1HGCM82633A123456");
        cars2[1] = Vehicle("Ford", "Green", 2017, "5YJSA1E26JF252345");
        
        //array of pointers to objects
        Vehicle** cars3 = new Vehicle*[size];
        cars3[0] = new Vehicle("Audi", "White", 2019, "1HGCM82633A123456");
        cars3[1] = new Vehicle("Ford", "Green", 2017, "5YJSA1E26JF252345");

        //print dynamic objects
        for(int i = 0; i < size; i++) {
            cout << cars1[i]->toString() << endl;
        }

        for(int i = 0; i < size; i++) {
            cout << cars2[i].toString() << endl;
        }

        for(int i = 0; i < size; i++) {
            cout << cars3[i]->toString() << endl;
        }

        //counter
        cout << "\nTotal objects created: " << Vehicle::getObjectsCount() << endl;

        //delete dynamic objects
        for(int i = 0; i < size; i++) {
            delete cars1[i];
            delete cars3[i]; //delete each object
        }

        delete[] cars2;
        delete[] cars3; //deleate array of pointers

        cout << "\nAfter deleting dynamic objects:" << endl;
        cout << "Total objects remaining: " << Vehicle::getObjectsCount() << endl;
    }
    //cathing invalind vin and production year
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
