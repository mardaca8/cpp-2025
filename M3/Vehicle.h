#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class VehicleImpl;

class Vehicle {
public:
    Vehicle();
    Vehicle(const std::string& brand);
    Vehicle(const std::string& brand, const std::string& color, int year, const std::string& vin);
    Vehicle(const Vehicle& other); 
    Vehicle& operator=(const Vehicle& other); 
    ~Vehicle();

    std::string getBrand() const;
    std::string getColor() const;
    int getYear() const;
    std::string getVin() const;
    std::string toString() const;

    void setBrand(const std::string& brand);
    void setColor(const std::string& color);
    void setYear(int year);
    void setVin(const std::string& vin);

    static int getObjectsCount();

    void setEngine(class Engine* engine);
    void switchEngine(int type);

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);
    friend std::istream& operator>>(std::istream& is, Vehicle& v);

private:
    VehicleImpl* impl; // Pointer to implementation
};

#endif // VEHICLE_H


#ifndef INVALID_VEHICLE_EXCEPTION_H
#define INVALID_VEHICLE_EXCEPTION_H

#include <stdexcept>
#include <string>

class InvalidVehicleException : public std::runtime_error {
public:
    explicit InvalidVehicleException(const std::string& message)
        : std::runtime_error("InvalidVehicleException: " + message) {}
};

#endif

