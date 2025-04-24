#include "Vehicle.h"
#include "Engine.h"
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

    Engine* engine;

    VehicleImpl() : brand("Unknown"), color("Unknown"), year(2000), vin("XXXXXXXXXXXXXXXXX"), id(idCounter++), engine(new PetrolEngine()) {
        objectsCount++;
    }

    VehicleImpl(const std::string& b, const std::string& c, int y, const std::string& v, Engine* eng = nullptr)
        : brand(b), color(c), year(y), vin(v), id(idCounter++), engine(eng ? eng->clone() : new PetrolEngine()) {
        validate();
        objectsCount++;
    }

    VehicleImpl(const VehicleImpl& other)
        : brand(other.brand), color(other.color), year(other.year), vin(other.vin), id(idCounter++), engine(other.engine->clone()) {
        objectsCount++;
    }

    ~VehicleImpl() {
        delete engine;
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
        ss << "Brand: " << brand << " | Color: " << color << " | Year: " <<  year << " | VIN: " << vin << " | ID: " << id << " | Engine: " << engine->getType() << " | Horsepower: " << engine->getHorsepower();
        
        return ss.str();
    }

    void setEngine(Engine* newEngine) {
        if (engine) delete engine;
        engine = newEngine->clone();
    }
   
    void switchEngine(int type) {
        int currentHP = engine->getHorsepower();
        Engine* newEngine = nullptr;
        switch(type) {
            case 0:
                newEngine = new PetrolEngine(currentHP);
                break;
            case 1:
                newEngine = new DieselEngine(currentHP);
                break;
            case 2:
                newEngine = new ElectricEngine(currentHP);
                break;
            default:
                throw std::invalid_argument("Invalid engine type");
        }
        delete engine;
        engine = newEngine;
    }

    void save(std::ostream& os) const {
        int len;
    
        len = brand.size();  os.write((char*)&len, sizeof(len)); os.write(brand.c_str(), len);
        len = color.size();  os.write((char*)&len, sizeof(len)); os.write(color.c_str(), len);
        os.write((char*)&year, sizeof(year));
        len = vin.size();    os.write((char*)&len, sizeof(len)); os.write(vin.c_str(), len);
    
        engine->save(os);
    }
    
    void load(std::istream& is) {
        int len;
        char buffer[256];
    
        is.read((char*)&len, sizeof(len)); is.read(buffer, len); buffer[len] = 0; brand = buffer;
        is.read((char*)&len, sizeof(len)); is.read(buffer, len); buffer[len] = 0; color = buffer;
        is.read((char*)&year, sizeof(year));
        is.read((char*)&len, sizeof(len)); is.read(buffer, len); buffer[len] = 0; vin = buffer;
    
        // engine type
        is.read((char*)&len, sizeof(len));
        is.read(buffer, len); buffer[len] = 0;
        std::string engineType = buffer;
    
        int hp;
        is.read((char*)&hp, sizeof(hp));
    
        delete engine;
        if (engineType == "Petrol") engine = new PetrolEngine(hp);
        else if (engineType == "Diesel") engine = new DieselEngine(hp);
        else if (engineType == "Electric") engine = new ElectricEngine(hp);
        else engine = new PetrolEngine(hp); // default fallback
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

void Vehicle::setEngine(Engine* engine) {
    impl->setEngine(engine);
}

void Vehicle::switchEngine(int type) {
    impl->switchEngine(type);
}

std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
    v.impl->save(os);
    return os;
}

std::istream& operator>>(std::istream& is, Vehicle& v) {
    v.impl->load(is);
    return is;
}
