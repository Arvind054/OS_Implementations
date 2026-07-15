// Build Your own Semaphore

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

class Semaphore{
    private:
       int count;
       mutex m;
       condition_variable cv;

    public:
       Semaphore(int permits){
        count = permits;
       }

       void acquire(){
         unique_lock<mutex> lock(m);
         cv.wait(lock, [&]{return count > 0;});
         count--;
       }

       void release(){
        {
        lock_guard<mutex>lock(m);
        count++;
        }
        cv.notify_one();
       }
};