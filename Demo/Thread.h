#ifndef PTHREAD_H
#define PTHREAD_H

#include<thread>

class Thread
{
public:
    typedef pthread_t ThreadId;
    Thread() {
        _id = 0;
    }
    virtual ~Thread() {
    }
    static void sleep(int millis);
    ThreadId getId() const;
    virtual void start();
    virtual void join();
    virtual void detach();
    virtual void run()=0;
private:
    ThreadId _id;
};

#endif // PTHREAD_H
