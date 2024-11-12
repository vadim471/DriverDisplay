#include "MonitorDriver.h"
#include <iostream>

MonitorDriver::MonitorDriver(const std::string& port) : serialPort(port) {
    if (serialPort.isOpen()) {
        std::cout << "Serial port is opened" << std::endl;
    } else {
        std::cout << "Failed to open serial port" << std::endl;
    }

    void MonitorDriver::setBrightness(int value) {
        if (value < 20 || value > 100) {
            std::cerr << "Brightness out of range (20, 100)" << std::endl;
            return;
        }
        sendCommand("bright " + std::to_string(value) + "\n");
    }

    std::string MonitorDriver::getStatus() {
        sendCommand("stat" + "\n")
        return getResponse();
    }

    std::string MonitorDriver::getConfig() {
        sendCommand("cfg" + "\n");
        return getResponse();
    }

    void MonitorDriver::sendCommand(std::string& command) {
        serialPort.write(command);
    }

    std::string MonitorDriver::getResponse() {
        return serialPort.read();
    }
}