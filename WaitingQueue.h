#ifndef WAITINGQUEUE_H_INCLUDED
#define WAITINGQUEUE_H_INCLUDED

class WaitingQueue
{
    public:
        WaitingQueue();
        ~WaitingQueue();

        void add(Tramway* tramway);
        Tramway* quit();

        bool empty() const;

    private:
        Tramway *m_first, *m_last;
};

#endif // WAITINGQUEUE_H_INCLUDED
