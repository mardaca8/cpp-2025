#ifndef ENGINE_H
#define ENGINE_H

#include <string>

class Engine {
public:
    virtual ~Engine() = default;

    virtual std::string getType() const = 0;
    virtual Engine* clone() const = 0;

    virtual int getHorsepower() const = 0;
    virtual void setHorsepower(int hp) = 0;
};

class PetrolEngine : public Engine {
    int horsepower;
public:
    PetrolEngine(int hp = 150) : horsepower(hp) {}
    std::string getType() const override { return "Petrol"; }
    Engine* clone() const override { return new PetrolEngine(*this); }

    int getHorsepower() const override { return horsepower; }
    void setHorsepower(int hp) override { horsepower = hp; }
};

class DieselEngine : public Engine {
    int horsepower;
public:
    DieselEngine(int hp = 130) : horsepower(hp) {}
    std::string getType() const override { return "Diesel"; }
    Engine* clone() const override { return new DieselEngine(*this); }

    int getHorsepower() const override { return horsepower; }
    void setHorsepower(int hp) override { horsepower = hp; }
};

class ElectricEngine : public Engine {
    int horsepower;
public:
    ElectricEngine(int hp = 200) : horsepower(hp) {}
    std::string getType() const override { return "Electric"; }
    Engine* clone() const override { return new ElectricEngine(*this); }

    int getHorsepower() const override { return horsepower; }
    void setHorsepower(int hp) override { horsepower = hp; }
};

#endif // ENGINE_H
