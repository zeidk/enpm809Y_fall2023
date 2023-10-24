#include "aggregation/sensor.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <random>

//==============================================================================
void MazeNavigation::Sensor::update_data(){
    std::cout << "Updating data from sensor " << sensor_name_ << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(1));
    sensor_data_ = 1.0;
}

//==============================================================================
void MazeNavigation::Sensor::start_reading(unsigned int period) {

    std::cout << "Starting reading from sensor " << sensor_name_ << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(period));
    //generate random double between 1 and 100
    std::random_device rd;  // Random device engine, usually based on
                            // /dev/urandom on UNIX-like OSes
    std::mt19937 gen(rd());  // Initializes with the random device
    std::uniform_real_distribution<> dis(1.0, 100.0);
    sensor_data_ = dis(gen);
    std::cout << "Sensor " << sensor_name_ << " read data: " << sensor_data_ << '\n';
    stop_reading();
}

//==============================================================================
void MazeNavigation::Sensor::stop_reading() {
    std::cout << "Stopping reading data" << '\n';
}

//==============================================================================
double MazeNavigation::Sensor::get_sensor_data() {
    return sensor_data_;
}