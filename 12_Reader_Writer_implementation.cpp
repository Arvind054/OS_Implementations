// Implement Your Own Reader-Writer Lock:


#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

class RwLock{
    private:
        mutex m;
        condition_variable cv;
        int readers = 0;
        bool writing  = false; 
    public:
    void readLock(){
        unique_lock<mutex>lock(m);
        cv.wait(lock, [&]{return !writing;});
        readers++;
    }
    void readUnlock(){
         unique_lock<mutex>lock(m);
         readers--;
       if(readers == 0)cv.notify_all();
    }

    void writeLock(){
        unique_lock<mutex>lock(m);
        cv.wait(lock, [&]{return !writing && readers == 0;});
        writing  = true;
    }
    void writeUnlock(){
        unique_lock<mutex>lock(m);
        writing  = false;
        cv.notify_all();
    }

};
