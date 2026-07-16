/*
  Reader-Writer Lock (Shared Mutex)
  Since Reading not changes the Data, we can allow multiple threads to read but
   only one thread to write the data and also reading and writing should not be
    done together.
    Multiple readers allowed OR One writer allowed ::--> Never both together.
    using shared Mutex:
    lock_shared() , unlock_shared() ,lock() ,unlock()
    lock_shared allow mutliple to enter and lock allow only one.
*/

#include<iostream>
#include<thread>
#include<shared_mutex>
#include<chrono>
#include <syncstream>
using namespace std;
shared_mutex rw;
int balance = 100;


void reader(int readerId){
  rw.lock_shared();
  this_thread::sleep_for(chrono :: seconds(3));
  osyncstream(cout)<<"Reader :: "<<readerId<<" is Reading : "<<balance<<endl;
   rw.unlock_shared();
}

void writer(){
  rw.lock();
  balance += 50;
  rw.unlock();
}

int main(){
  thread t1(reader, 1);
  thread t2(reader, 2);
  thread t4(reader, 4);
  thread t3(writer);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  return 0;
}

/*
 Like lock_guard we can use shared_lock<mutex>lock(rw) for readers and for writers we can use 
 unique_lock<mutex>lock(rw);
*/