// Semaphores: 

/*
Why isn't a mutex enough? : A mutex allows only one thread inside.

Semaphore is a counter that allows N threads to access the critical section simultaneously.
A semaphore has two operations: acquire and release.

acquire means if count > 0 then allow and count--, otherwise sleep.
release means leaving then count++;

*/

#include<iostream>
#include<thread>
#include<semaphore>
#include <chrono>
using namespace std;
// intside <> : maximum Value and constructor holds current value.
counting_semaphore<3>sem(3);


void worker(int id){
   sem.acquire();
   cout<<"Thread : "<<id<<" Started."<<endl;
   this_thread::sleep_for(chrono::seconds(3));
   cout<<"Thread : "<<id<<" Completed."<<endl;
   sem.release();

}
int main(){
    cout<<endl;
   thread t1(worker, 1);
   thread t2(worker, 2);
   thread t3(worker, 3);
   thread t4(worker, 4);
   t1.join();
   t2.join();
   t3.join();
   t4.join();
   cout<<"Completed."<<endl;
   return 0;
}