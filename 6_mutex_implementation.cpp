// Build you own version of Mutex.
//A simple mutex can be implemented as a spin lock.

#include<iostream>
#include<atomic>
#include<thread>
using namespace std;

/*
This is not the exact way mutex works as it has busy waiting and it wastes cpu cycles.
A mutex blocks waiting threads instead of making them continuously consume CPU while waiting.
and not a spin lock wastes the CPU cycle.
*/
class myMutex{
    private: 
    atomic<bool>locked{false};
    public:
    void lock(){
        while(locked.exchange(true)){

        }
    }
    void unlock(){
        locked.store(false);
    }
};

myMutex m;
int counter = 0;
void update(){
    
    for(int i = 1; i<=100000; i++){
        m.lock();
       counter++;
       m.unlock();
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