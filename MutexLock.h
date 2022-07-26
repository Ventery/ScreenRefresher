#ifndef MUTEXLOCK_H
#define MUTEXLOCK_H

#include <pthread.h>
#include <cstdio>
#include "noncopyable.h"

class MutexLock : Noncopyable
{
public:
    MutexLock() { pthread_mutex_init(&mutex_, NULL); }
    ~MutexLock()
    {
        pthread_mutex_lock(&mutex_);
        pthread_mutex_destroy(&mutex_);
    }
    void Lock() { pthread_mutex_lock(&mutex_); }
    void UnLock() { pthread_mutex_unlock(&mutex_); }
    pthread_mutex_t *Get() { return &mutex_; }

private:
    pthread_mutex_t mutex_;
};

class MutexLockGuard : Noncopyable
{
public:
    explicit MutexLockGuard(MutexLock &mutex) : mutex_(mutex) { mutex_.Lock(); }
    ~MutexLockGuard() { mutex_.UnLock(); }

private:
    MutexLock &mutex_;
};

#endif // MUTEXLOCK_H
