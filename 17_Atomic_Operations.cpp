/*
 A mutex is based on Atomic Operations.
  Atomic means: Either the entire operation happens, or none of it happens.

  For example: Counter++ happens lik: temp = counter; temp = temp+1; counter = temp;
  if two threads try to access or update we get diffent results.
*/

#include<atomic>
using namespace std;

atomic<int> counter{0}; 
atomic<bool>flag{false};
// when doing counter++ , it happens in One CPU cycle counter = 1;
int main(){
    int value = counter.load();
    counter.store(20); // same as counter = 20;
 
    return 0;
}

/* 
A mutex protects a critical section, not just one variable.
Use an atomic when:
                    A single variable is shared.
                    The operation is simple (increment, decrement, read, write, exchange).

Use a mutex when:
                    Multiple variables must stay consistent.
                    Multiple operations form one logical unit.
*/
