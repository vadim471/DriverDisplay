CXX = g++
CXXFLAGS = -std=c++17 -I./src
LDFLAGS = -lboost_system

SRC_DIR = src
TEST_DIR = "./test"

SRC_FILES = $(SRC_DIR)/SerialPort.cpp $(SRC_DIR)/MonitorDriver.cpp
MAIN_FILE = $(SRC_DIR)/Main.cpp
TEST_FILE = $(TEST_DIR)/TestDriver.cpp

all: main test_driver


main: $(MAIN_FILE) $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -o main $(MAIN_FILE) $(SRC_FILES) $(LDFLAGS)

test_driver: $(TEST_FILE) $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -o test_driver $(TEST_FILE) $(SRC_FILES) $(LDFLAGS)

clean:
	rm -f main test_driver