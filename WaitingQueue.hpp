#ifndef WAITINGQUEUE_H_INCLUDED
#define WAITINGQUEUE_H_INCLUDED

#include <cstdlib>

class Tramway;

class WaitingQueue
{
    public:
        WaitingQueue();
        ~WaitingQueue();

        void push(Tramway* tramway);
        Tramway* pop();

        bool empty() const;

    private:
        Tramway *m_first, *m_last;
};

#endif // WAITINGQUEUE_H_INCLUDED
