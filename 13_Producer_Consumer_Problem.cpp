
/*
 Producer Consumer Problem:
 Producer Produces and Consumer Consumers. Producer Should wait if the Q if full ans
  consumer should wait if the Q is Empty.
*/

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
#include<syncstream>
using namespace std;

mutex m;
queue<int>q;
condition_variable cv;
int MAX_SIZE  = 5;
void producer(){
    for(int i = 1; i<=10; i++){
    unique_lock<mutex>lock(m);
    cv.wait(lock, []{return q.size() < MAX_SIZE;});
    q.push(i);
    osyncstream(cout)<<"Produced: "<<i<<endl;
    lock.unlock();
    cv.notify_one();
    }
}

void consumer(){
    for(int i = 1; i<=10; i++){
     unique_lock<mutex>lock(m);
     cv.wait(lock, []{return !q.empty();});
      osyncstream(cout)<<"Consumed : "<<q.front()<<endl;
     q.pop();
     lock.unlock();
     cv.notify_one();
    }
}

int main(){

     thread t1(producer);
     thread t2(consumer);
     t1.join();
     t2.join();
    return 0;
}