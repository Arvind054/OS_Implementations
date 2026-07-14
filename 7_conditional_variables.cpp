/*
   Conditional Variables: 
   Generally in Mutex or Locks the thread keeps busy wiating that wastes CPU cycles,
    so a conditional variable avoid busy waiting by making the thread sleep and wakes 
    it up when some condition happens.
*/

/*
Three Important Functions:
   wait()
notify_one()
notify_all()
*/
#include<iostream>
#include<condition_variable>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

mutex m;
condition_variable cv;
 bool ready = false;

 void consumer(){
     unique_lock<mutex>lock(m);
     //cv.wait(lock); // what if the producer is ready before consumer startes, this will make it wait
     cv.wait(lock, []{return ready;});
     cout<<"Consumer Started"<<endl;
 }

 void producer(){
    lock_guard<mutex>lock(m);
    ready = true;
    cout<<"Producer Ready"<<endl;
    cv.notify_all();
 }
int main(){
    thread t1(consumer);
    this_thread::sleep_for(chrono::seconds(5));
    thread t2(producer);
    t1.join();
    t2.join();
    return 0;
}

/*
 Why using Mutex: beacuse both threads access ready at the same time
 and if producer tries to update it this is a race condition.

 Why does wait() require unique_lock? : Only unique_lock supports temporarily unlocking and 
 relocking the mutex automatically.lock_guard cannot do this.

 the mutex is released while the consumer sleeps, otherwise the producer could never acquire
  it to change ready. This automatic unlock-before-sleep and relock-after-wakeup
   is exactly why wait() takes a std::unique_lock.
*/