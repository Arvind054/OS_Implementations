
// Compare and Swap(CAS):

/*
   Why we need CAS, image checking if(val >= 20)val++;
   what if another thread tries to change val when we are checking ??
   Only update the value if nobody has changed it since I last read it.
   CAS says: It says: If current value == expected value -> Replace it -> Else -> Do nothing.
*/

#include<iostream>
#include<atomic>
using namespace std;

atomic<int> balance = 100;
int main(){
    int expected = 100;
    bool success = balance.compare_exchange_strong(expected, 80);
};

// CAS Loop

atomic<int>counter{10};
void increment(){
    int old = counter.load();
    while(!counter.compare_exchange_strong(old, old+1)){
        // retry
    }
}

/* 
compare_exchange_
Strong: fails only when the value actually doesn't match.
Weak: is allowed to fail even when the value matches (called a spurious failure).
*/