#ifndef ENERGYMONITOR_H
#define ENERGYMONITOR_H
#include <iostream>
#include <fstream>
#include <string.h>
#include "MyStr.h"
#include <ctime>
using namespace std;
class EnergyMonitor {
private:

    ofstream logfile;

public:

    EnergyMonitor();
    void initialize(const MyStr& filename);
    void cleanup();
    void writeUpdate(const MyStr& error_message);

};
#endif // !EVENTLOGGER_H
