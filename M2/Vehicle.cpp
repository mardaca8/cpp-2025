#include "Vehicle.h"
#include <sstream>
#include <stdexcept>


// VEHICLE implementation
// Implementation of the Vehicle class using the Pimpl idiom
class VehicleImpl {
public:
    std::string brand;
    std::string color;
    int year;
    std::string vin;
    int id;

    static int idCounter;
    static int objectsCount;

    VehicleImpl() : brand("Unknown"), color("Unknown"), year(2000), vin("XXXXXXXXXXXXXXXXX"), id(idCounter++) {
        objectsCount++;
    }

    VehicleImpl(const std::string& b, const std::string& c, int y, const std::string& v)
        : brand(b), color(c), year(y), vin(v), id(idCounter++) {
        validate();
        objectsCount++;
    }

    VehicleImpl(const VehicleImpl& other)
        : brand(other.brand), color(other.color), year(other.year), vin(other.vin), id(idCounter++) {
        objectsCount++;
    }

    ~VehicleImpl() {
        objectsCount--;
    }

    void validate() const {
        if (year < 1900 || year >= 2025)
            throw InvalidVehicleException("Invalid production year: " + std::to_string(year));
        if (vin.length() != 17)
            throw InvalidVehicleException("Invalid VIN number: " + vin);
    }

    std::string toString() const {
        std::stringstream ss;
        ss << "Brand: " << brand << " | Color: " << color << " | Year: " << year
           << " | VIN: " << vin << " | ID: " << id;
        return ss.str();
    }
};

int VehicleImpl::idCounter = 1;
int VehicleImpl::objectsCount = 0;

// VEHICLE methods

Vehicle::Vehicle() : impl(new VehicleImpl()) {}

Vehicle::Vehicle(const std::string& brand)
    : impl(new VehicleImpl()) {
    impl->brand = brand;
}

Vehicle::Vehicle(const std::string& brand, const std::string& color, int year, const std::string& vin)
    : impl(new VehicleImpl(brand, color, year, vin)) {}

Vehicle::Vehicle(const Vehicle& other)
    : impl(new VehicleImpl(*other.impl)) {} // copy constructor

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        delete impl;
        impl = new VehicleImpl(*other.impl);
    }
    return *this;
}

Vehicle::~Vehicle() {
    delete impl;
}

std::string Vehicle::getBrand() const { return impl->brand; }
std::string Vehicle::getColor() const { return impl->color; }
int Vehicle::getYear() const { return impl->year; }
std::string Vehicle::getVin() const { return impl->vin; }

void Vehicle::setBrand(const std::string& brand) { impl->brand = brand; }
void Vehicle::setColor(const std::string& color) { impl->color = color; }
void Vehicle::setYear(int year) { impl->year = year; impl->validate(); }
void Vehicle::setVin(const std::string& vin) { impl->vin = vin; impl->validate(); }

std::string Vehicle::toString() const { return impl->toString(); }

int Vehicle::getObjectsCount() { return VehicleImpl::objectsCount; }
