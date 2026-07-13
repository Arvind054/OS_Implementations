/* A thread is a single Squence stream within a Process.
   or a Thread is an independent path of execution within a Process. Each Thread has it's own stack, registers and Programme Counter.
*/

#include<iostream>
#include<thread>
using namespace std;

void testThread(){
    cout<<"Hello from thread"<<endl;
}
int main(){
    thread t1(testThread);
    thread t2(testThread);
    t1.join();
    t2.join();
    cout<<"Hello from main: "<<endl;
    return 0;
}

/* The t1.join joins the execution for the thread with the mina thread so that the main thread won't exit before completion of the threads.*/