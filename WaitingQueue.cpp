#include "WaitingQueue.h"

WaitingQueue::WaitingQueue() : m_first(NULL), m_last(NULL) {}

WaitingQueue::~WaitingQueue()
{
    while(m_first)
        quit();
}

WaitingQueue::empty()
{
    return m_first == NULL;
}
