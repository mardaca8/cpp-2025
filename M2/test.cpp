#include <iostream>
#include <fstream>
#include "Vehicle.h"


using namespace std;

void logTest(const string& result, ofstream& log) {
    cout << result << endl;
    log << result << endl;
}

int main() {
    ofstream log("vehicle_test_log.txt");

    if (!log.is_open()) {
        cerr << "Failed to open log file" << endl;
        return 1;
    }

    logTest("beginning of the test", log);

    try {
        Vehicle v1("Audi", "White", 2020, "12345678901234567");
        logTest("created v1: " + v1.toString(), log);
    } catch (const exception& e) {
        logTest("failed to create v1: " + string(e.what()), log);
    }

    try {
        Vehicle v2("BMW", "Blue", 1890, "12345678901234567");
        logTest("should not be created", log);
    } catch (const InvalidVehicleException& e) {
        logTest("InvalidVehicleException invalid year: " + string(e.what()), log);
    } catch (...) {
        logTest("invalid exception", log);
    }

    try {
        Vehicle v3("Mercedes", "Black", 2020, "1234");
        logTest("should not be created", log);
    } catch (const InvalidVehicleException& e) {
        logTest("InvalidVehicleException invalid VIN: " + string(e.what()), log);
    } catch (...) {
        logTest("invalid exception", log);
    }

    try {
        Vehicle v4("Lexus", "Silver", 2023, "12345678901234567");
        v4.setYear(1800); // klaidingi metai
        logTest("setyear should not be allowed", log);
    } catch (const InvalidVehicleException& e) {
        logTest("InvalidVehicleException from setYear: " + string(e.what()), log);
    }

    logTest("end", log);
    log.close();

    return 0;
}
