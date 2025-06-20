#include "DataQueue.h"
#include <thread>


DataQueue::DataQueue()
{


}


DataQueue::~DataQueue()
{

}


void DataQueue::push(const std::string& data)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_queue.push(data);
    m_cond.notify_one();
}

 std::string DataQueue::pop() 
 {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_cond.wait(lock, [&]{ return !m_queue.empty(); });
    std::string data = m_queue.front();
    m_queue.pop();
    return data;
 }