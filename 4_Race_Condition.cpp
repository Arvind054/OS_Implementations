/*
 What is a Race Condition ? :
  A race condition occurs when: Two or more threads Access the same memory and At least one
  thread modifies it And there is no synchronization. The result depends on which thread runs first.
*/

/*
What is the Critical Section? 
The critical section is the part of the code that accesses shared data and therefore must not be executed by multiple threads at the same time.
*/
#include<iostream>
#include<thread>
using  namespace std;

int counter = 0;
void update(){
     for(int i = 1; i<=100000; i++){
        counter++;
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