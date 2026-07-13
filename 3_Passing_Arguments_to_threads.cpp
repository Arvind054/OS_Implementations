//Passing Arguments to Threads

#include<iostream>
#include<thread>
using namespace std;
//Passing By Value
/* void printNumber(int x){
    cout<<"The Number is : "<<x<<endl;
 }
 int main(){
    thread t(printNumber, 10); 
    t.join();
    return 0;
 }
    */


//Passing By Refrence

/* Directly using & operator and passing the value will will thourgh error and the code will not compile beacuse the thread makes the copy of each argument passed to it.
 void printNumber(int& x){
    x++;
    cout<<"The Number is : "<<x<<endl;
 }
 int main(){
    int x = 10;
    thread t(printNumber, x);  
    t.join();
    cout<<"The Final Number is: "<<x<<endl;
    return 0;
 }
    */

    // To avoid this use Std::ref
    /*
#include <functional>

    void printNumber(int& x){
    x++;
    cout<<"The Number is : "<<x<<endl;
 }
 int main(){
    int x = 10;
    thread t(printNumber, ref(x));  
    t.join();
    cout<<"The Final Number is: "<<x<<endl;
    return 0;
 }

 */
 /* Why this Works: it doesn't create a reference, it creates a tiny object called refrence_wrapper and instead of value it stores the address of the variable and when the thread starts it unwraps that object and passes the original value by reference. */

 // Passing Multiple Arguments, string, Lambda Funtion

 /*
 void printName(string name){
    cout<<"Name is : "<<name<<endl;
 }
 void addNum(int num1, int num2){
    cout<<"Sum is: "<<num1 + num2<<endl;
 }

 int main(){
    thread t1(printName, "Hello");
    thread t2(addNum, 1,2);
    thread t3([](int a, int b){cout<<"Product is : "<<a*b<<endl;}, 1,2);
    t1.join();
    t2.join();
    t3.join();
    return 0;
 }
    */

    // Race Condition: Two threads trying to change the Same Value

    void update(int & num){
        for(int i = 0; i<5; i++){
            num++;
        }
        cout<<num<<endl;
    }
    int main(){
         int x = 0;
        thread t1(update, ref(x));
        thread t2(update, ref(x));
        t1.join();
        t2.join();
        cout<<x<<endl;
        return 0;
    }