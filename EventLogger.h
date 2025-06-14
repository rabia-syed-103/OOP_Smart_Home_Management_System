#ifndef EVENTLOGGER_H
#define EVENTLOGGER_H
#include <iostream>
#include <fstream>
#include <string.h>
#include "MyStr.h"
#include <ctime>
using namespace std;
class EventLogger {
private:
    
    fstream logfile;
  
public:

    EventLogger();
    void initialize(const MyStr& filename);
    void cleanup();
    void writeError(const MyStr& error_message); 
    void writeMessage(const MyStr& message);
    void PrintLog();
    ~EventLogger();

};
#endif // !EVENTLOGGER_H
