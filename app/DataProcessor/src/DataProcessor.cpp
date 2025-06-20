#include "DataProcessor.h"
#include <string>
#include <thread>
#include <iostream>

DataProcessor::DataProcessor(DataQueue& queue) : m_queue(queue) {}

void DataProcessor::start() 
{
    std::thread([this] {
        while (true) {
        std::string data = m_queue.pop();
        std::cout << "Przetwarzam dane: " << data << std::endl;
        }
    }).detach();
}