#include "SerialPort.h"
#include <iostream>

SerialPort::SerialPort(const std::string& port, unsigned int baud_rate) : io(), serial(io, port) {
    setBaudRate(baud_rate);
    setCharacterSize(8);
    setFlowControl(boost::asio::serial_port_base::flow_control::none);
    setParity(boost::asio::serial_port_base::parity::none);
    setStopBits(boost::asio::serial_port_base::stop_bits::two);
}

bool SerialPort::isOpen() const {
    return serial.is_open();
}

void SerialPort::write(const std::string& command) {
    boost::asio::write(serial, boost::asio::buffer(command));
}

std::string SerialPort::read() {
    boost::asio::streambuf buf_response;
    std::string response;

    try {
        while (true)
        {
            boost::asio::read(serial, buf_response, boost::asio::transfer_at_least(1));
            std::istream response_stream(&buf_response);
            std::string line;

            while (std::getline(response_stream, line, ' ')) {
                response += line + " ";
            }

            if (buf_response.size() == 0) {
                break;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error reading " << e.what() << std::endl;
        }
        
        return response;
    }
}