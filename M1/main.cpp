#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

class Vehicle {
    private:
        string name;
        string color;
        int year;
        int vin;

        static int objectsCount;

    public:
        Vehicle(string name, string color, int year){
            this->name = name;
            this->color = color;
            this->year = year;
            this->vin = vin;
            objectsCount++;
        }

        //desctructor
        ~Vehicle(){
            objectsCount--;
        }
        //getters
        string getName(){
            return name;
        }

        string getColor(){
            return color;
        }
        
        int getYear(){
            return year;
        }

        int getVin(){
            return vin;
        }

        static int getObjectsCount(){
            return objectsCount;
        }

};



int main () {
    Vehicle**  vehicle[5];
    
    return 0;
}
