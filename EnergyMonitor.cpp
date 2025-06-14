#include "EnergyMonitor.h"

EnergyMonitor::EnergyMonitor()
{
}

void EnergyMonitor::initialize(const MyStr& filename) {
    string _filename = std::string(filename.c_str());
    logfile.open(_filename);
    if (!logfile)
    {
        cout << "This file can't be opened!";
    }
    logfile << "All Energy Updates \n";
}
void EnergyMonitor::cleanup() {

    logfile.close();

}
void EnergyMonitor::writeUpdate(const MyStr& error_message) {
    time_t timestamp;
    time(&timestamp);

    char timeStr[26];
    ctime_s(timeStr, sizeof(timeStr), &timestamp);
    logfile << "Update Time :: " << timeStr;
    logfile << "Update :: " << error_message << endl;
}

EnergyMonitor::~EnergyMonitor()
{
}

void EnergyMonitor::PrintEnergyMonitor()
{
    cout << "\nAll Energy Updates\n\n";
    logfile.seekg(0);
    MyStr message;

    while (logfile >> message)
    {

        cout << message << ' ';
    }
}
