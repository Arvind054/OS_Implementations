/*
 How do we make sure only one thread accesses a critical section at a time?
 By Using Mutex.

 We want that at a time only one thread access the critical section.

 What is a Mutex? : -> A mutex is simply a lock.

 When a thread loks the mutex then others threads cannot lock it and has to wait
  until it is released to access the critical section. at a time only one thread
   can access the critical section.
*/


/*
 What is locg_guard: When after locking and before unlocking there is any exception the thread
 therminates and doesnot unlocks and the lock remains forever so the other threads waits 
 forever and the system is in deadlock. 
 to avoid this use lock_guard.
 When the lock goest out of scope lock_guard's distructor calls unlock.

 unique_lock : it allows automatic unlock as well as manual lock and unlock. but is slightly slower.
*/

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex m;
int counter = 0;
void update(){
    
    for(int i = 1; i<=100000; i++){
        //  m.lock();
        //lock_guard<mutex> lock(m);
        unique_lock<mutex> lock(m);
        lock.unlock();
        lock.lock();

       counter++;
      // m.unlock();
    }
}

int main(){
      
    thread t1(update);
    thread t2(update);
    thread t3(update);
    thread t4(update);
     t1.join();
     t2.join();
     t3.join();
     t4.join();
    cout<<counter<<endl;
    return 0;
}