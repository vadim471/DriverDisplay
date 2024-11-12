#ifndef MONITOR_DRIVER_H
#define MONITOR_DRIVER_H

#include "SerialPort.h"
#include <string>


using namespace std;

class MonitorDriver {
    public:
        MonitorDriver(const std::string& port);
        void setBrightness(int value);
        std::string getConfig();
        std::string getStatus();
    private:
        void sendCommand(const std::string& command);
        std::string getResponse();

        SerialPort serialPort();
}
#endif