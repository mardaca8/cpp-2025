#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

class Vehicle{
    private:
        string name;
        string color;
        int year;

        static int objectsCount;

    public:
        Vehicle(string name, string color, int year){
            this->name = name;
            this->color = color;
            this->year = year;
            objectsCount++;
        }

};



int main () {
    Vehicle**  vehicle[5];
    
    return 0;
}
