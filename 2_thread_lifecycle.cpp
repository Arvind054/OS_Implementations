/*
The Thread Lifecycle Consists of the following parts:

        Create -> Runnable -> Running -> Finished -> Joined OR Detached ->Destroyed
*/


#include<iostream>
#include<thread>
using namespace std;

void testThread(){
    cout<<"Hello from thread"<<endl;
}
int main(){
    thread t1(testThread);
    t1.detach();
    cout<<"Hello from main: "<<endl;
    return 0;
}

/*
 Join meaning: Wait until the worker thread finishes, then clean up its resources.
 Detech meaning: I don't want to manage this thread anymore. Let it run independently.
t1.detech deteches the thread from the main and now the thread is owned by the OS and when the main is completed the OS kills every thread.

Why does the program crash if we do neither?: 
When main() ends:
   -> t goes out of scope.
   -> Its destructor (~thread()) is called.
   -> The destructor checks:that t.joinable ->terminate
   Since you never called join() or detach(), the thread is still joinable, so the C++ standard requires std::terminate() to be called, which aborts the program.
*/