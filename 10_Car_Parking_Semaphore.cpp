// Implement Car parking Using Semaphore that allows to park 3 cars at most;

#include<iostream>
#include<thread>
#include<semaphore>
#include<chrono>
using namespace std;
counting_semaphore<3>sem(3);
void parkCar(int carNumber){
    sem.acquire();
    cout<<"Parked Car: "<<carNumber<<endl;
    this_thread::sleep_for(chrono:: seconds(5));
    cout<<"UnParked Car: "<<carNumber<<endl;
    sem.release();
}

int main(){

    thread t1(parkCar, 1);
    thread t2(parkCar, 2);
    thread t3(parkCar, 3);
    thread t4(parkCar, 4);
    thread t5(parkCar, 5);
    thread t6(parkCar, 6);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    return 0;
}
