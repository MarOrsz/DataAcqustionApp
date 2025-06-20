#pragma once



#include "DataQueue.h"



class DataProcessor {
public:
    DataProcessor(DataQueue& queue);
    void start();

private:
    DataQueue& m_queue;
};

