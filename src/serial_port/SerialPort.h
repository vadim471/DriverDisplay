#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H

#include <string>
#include <boost/asio.hpp>

class SerialPort {
    public:
        SerialPort(const std::string& port, unsigned int baud_rate = 115200);

        void setBaudRate(unsigned int baud_rate);
        void setCharacterSize(unsigned int size);
        void setStopBits(boost::asio::serial_port_base::stop_bits::type stop_bits);
        void setParity(boost::asio::serial_port_base::parity::type parity);
        void setFlowControl(boost::asio::serial_port_base::flow_control::type flow_control);

        bool isOpen() const;
        void write(const std::string& command);
        std::string read();
    
    private:
        boost::asio::io_service io;
        boost::asio::serial_port serial;
}

#endif