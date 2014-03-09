#include "WaitingQueue.hpp"

WaitingQueue::WaitingQueue() : m_first(NULL), m_last(NULL) {}

WaitingQueue::~WaitingQueue()
{
    while(m_first)
        pop();
}

bool WaitingQueue::empty() const
{
    return m_first == NULL;
}

Tramway* WaitingQueue::pop()
{

}
