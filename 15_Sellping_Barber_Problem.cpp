// Sleeping Barber Problem:

/*
 A barber With a Barber Chair and N waiting Chairs. Initially the barber is sleeping so when
 the first customer arrives the barber wakes up and performs the Hair cut, now while harcut is 
 going on if someone else arrives they have to wait on the waiting chairs if chairs available 
 else leaves. If there are no customers barber sleeps and does not check regularly.
*/


#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
using namespace std;

queue<int> waiting;
const int Chairs = 3;
mutex m;
condition_variable cv;

void barber(){
    while(true){
        unique_lock<mutex>lock(m);
        lock.lock();
        cv.wait(lock, []{return !waiting.empty();});
        int customer = waiting.front();
        waiting.pop();
        lock.unlock();
        //Performs Hair Cut;
    }
}
void customer(int id){
   unique_lock<mutex>lock(m);
   if(waiting.size() == Chairs){
      cout<<"No Enough Space, Customer Leaves."<<endl;
      return ;
   }
   waiting.push(id);
   cout<<"Customer "<<id<<" Waiting"<<endl;
   lock.unlock();
   cv.notify_one();
}