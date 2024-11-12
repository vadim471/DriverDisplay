#include <iostream>
#include "MonitorDriver.h"

int main() {
    try {
        MonitorDriver monitor("COM3");

        monitor.setBrightness(20);

        std::string status = monitor.getStatus();
        std::string config = monitor.getConfig();

        std::cout << "status" << status << "\nconfig" << config << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error" << e.what() << std::endl;
    }

    return 0;
}