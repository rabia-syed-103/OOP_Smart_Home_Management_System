#include "EventLogger.h"

EventLogger::EventLogger()
{
}

void EventLogger::initialize(const MyStr& filename) {
    string _filename = std::string(filename.c_str());
    logfile.open(_filename);
    if (!logfile)
    {
        cout << "This file can't be opened!";
    }
}
void EventLogger:: cleanup() {

    logfile.close();

}
void EventLogger::writeError(const MyStr& error_message) {
    time_t timestamp;
    time(&timestamp);

    char timeStr[26];
    ctime_s(timeStr, sizeof(timeStr), &timestamp);
    logfile << "Error Time :: " << timeStr;
    logfile << "Error :: " << error_message << endl;
}
void EventLogger::writeMessage(const MyStr& message) {
    time_t timestamp;
    time(&timestamp);

    char timeStr[26];
    ctime_s(timeStr, sizeof(timeStr), &timestamp);
    logfile << "Event Time :: " << timeStr;
    logfile << "Event :: " << message << endl;
}

void EventLogger::PrintLog()
{
    logfile.seekg(0);
    cout << "\nAll Event Updates\n\n";

    MyStr message;

    while (logfile >> message) 
    {
 
        cout << message << ' ';
    }
}

EventLogger::~EventLogger()
{

}
