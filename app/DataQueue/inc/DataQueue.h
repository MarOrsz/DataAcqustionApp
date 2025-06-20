#ifndef DATA_QUEUE_H
#define DATA_QUEUE_H

#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>

class DataQueue
{
    public:
        DataQueue();
        ~DataQueue();

        void push(const std::string& data);
        std::string pop();

    private:
        std::queue<std::string> m_queue;
        std::mutex m_mutex;
        std::condition_variable m_cond;
};

#endif