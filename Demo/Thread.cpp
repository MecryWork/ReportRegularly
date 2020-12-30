#include<pthread.h>
#include<thread>
#include"Thread.h"

void* vrvRunThread(void *target) {
    try {
        Thread* pT = reinterpret_cast<Thread*>(target);
        pT->run();
        pT->detach();
    } catch (...) {
    }
    return 0;
}

void Thread::sleep(int millis) {
    struct timespec ts;
    ts.tv_sec = millis / 1000;
    ts.tv_nsec = (millis % 1000) * 1000000;
    nanosleep(&ts, 0);
}

void Thread::start() {
    pthread_attr_t attr;
    int rc = pthread_attr_init(&attr);
    if (rc) {
        return;
    }
    rc = pthread_create(&_id, &attr, vrvRunThread, this);
    if (rc) {
        return;
    }
}

Thread::ThreadId Thread::getId() const {
    return _id;
}

void Thread::join() {
    if(_id <= 0)
        return;

    void* status = 0;
    int rc = pthread_join(_id, &status);
    if (rc) {
        return;
    }
    detach();
}

void Thread::detach() {
    if(_id<=0)
        return;

    int rc = pthread_detach(_id);
    if(rc != 0) {
        return;
    }
    _id=0;
}
