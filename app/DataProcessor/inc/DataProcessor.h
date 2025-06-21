#pragma once



#include "DataQueue.h"
#include "DbStore.h"



class DataProcessor {
public:
    DataProcessor(DataQueue& queue);
    void start();

private:
    DataQueue& m_queue;
    DbStore m_dbStore;
};

