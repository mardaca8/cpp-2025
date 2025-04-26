#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class VehicleImpl;

/**
 * @class Vehicle
 * @brief Reprezentuoja transporto priemonę su keičiamu variklio tipu.
 *
 * Naudoja Pimpl idiomą. Leidžia keisti variklio (Engine) realizaciją vykdymo metu.
 */

class Vehicle {
public:
    /**
     * @brief Konstruktorius be parametrų.
     */
    Vehicle();

    /**
     * @brief Konstruktorius su prekės ženklu.
     * @param brand Prekės ženklas.
     */
    Vehicle(const std::string& brand);

    /**
     * @brief Konstruktorius su prekės ženklu, spalva, gamybos metais ir VIN numeriu.
     * @param brand Prekės ženklas.
     * @param color Spalva.
     * @param year Gamybos metai.
     * @param vin VIN numeris.
     */
    Vehicle(const std::string& brand, const std::string& color, int year, const std::string& vin);

    /**
     * @brief Konstruktorius kopijai.
     * @param other Kitas objektas.
     */
    Vehicle(const Vehicle& other); 

    /**
     * @brief Priskyrimo operatorius.
     * @param other Kitas objektas.
     * @return Nuoroda į šį objektą.
     */
    Vehicle& operator=(const Vehicle& other); 

    /**
     * @brief Destruktorius.
     */
    ~Vehicle();

    /**
     * @brief Gauti prekės ženklą.
     * @return Prekės ženklas.
     */
    std::string getBrand() const;

    /**
     * @brief Gauti spalvą.
     * @return Spalva.
     */ 
    std::string getColor() const;

    /**
     * @brief Gauti gamybos metus.
     * @return Gamybos metai.
     */

    int getYear() const;

    /**
     * @brief Gauti VIN numerį.
     * @return VIN numeris.
     */
    std::string getVin() const;

    /**
     * @brief Gauti objekto aprašymą kaip tekstą.
     * @return Objekto aprašymas.
     */
    std::string toString() const;

    /**
     * @brief Nustatyti prekės ženklą.
     * @param brand Prekės ženklas.
     */
    void setBrand(const std::string& brand);

    /**
     * @brief Nustatyti spalvą.
     * @param color Spalva.
     */
    void setColor(const std::string& color);

    /**
     * @brief Nustatyti gamybos metus.
     * @param year Gamybos metai.
     */
    void setYear(int year);

    /**
     * @brief Nustatyti VIN numerį.
     * @param vin VIN numeris.
     */
    void setVin(const std::string& vin);

    /**
     * @brief Gauti objekto skaičių.
     * @return Objekto skaičius.
     */
    static int getObjectsCount();

    /**
     * @brief Nustatyti variklį.
     * @param engine Variklis.
     */
    void setEngine(class Engine* engine);

    /**
     * @brief Keisti variklį.
     * @param type Variklio tipas (0 - benzinas, 1 - dyzelinas, 2 - elektra).
     */
    void switchEngine(int type);


    /**
     * @brief Įrašo objektą į binarinį srautą.
     */
    friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);

    /**
     * @brief Nuskaito objektą iš binarinio srauto.
     */
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
    /**
     * @brief Konstruktorius su pranešimu.
     * @param message Pranešimas apie klaidą.
     */
    explicit InvalidVehicleException(const std::string& message)
        : std::runtime_error("InvalidVehicleException: " + message) {}
};

#endif

