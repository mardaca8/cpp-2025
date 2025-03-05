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
        string vin;

        static int objectsCount;

    public:
        Vehicle(string name, string color, int year, string vin){
            setdefaults();
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

        string getVin(){
            return vin;
        }

        static int getObjectsCount(){
            return objectsCount;
        }

        private:

        void setdefaults(){
            name = "unknown";
            color = "unknown";
            year = 1900;
            vin = "unknown";
            objectsCount++;
        }

        public:
        //setters
        void setName(string name){
            this->name = name;
        }

        void setColor(string color){
            this->color = color;
        }

        void setYear(int year){
            if (year < 1900 || year > 2025){
                throw invalid_argument("Invalid production year");
            }
            else {
                this->year = year;
            }
        }

        void setVin(string vin){
            if(vin.length() != 17){
                throw invalid_argument("Invalid VIN number");
            }
            else { 
                this->vin = vin;
            }
        }
};



int main () {
    Vehicle**  vehicle[5];
    
    return 0;
}
