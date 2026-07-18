/*
  Dining Philosophers Problem: 
  Five philosophers sitting around a circular table.Each philosopher has: One fork on the left and 
  One fork on the right. A philosopher can only eat if they have both forks. Otherwise they think.
  Since forks are shared resources is is a synchronization Problem.
*/


#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
// First Solution Using Mutex

/*
mutex forks[5];

void philosopher(int id){
    while(true){
        //think();
        forks[id].lock();
        forks[(id+1)%5].lock();
        //eat();
        forks[id].unlock();
        forks[(id+1)%5].unlock();
    }
}

 This Programme can freeze forever, why ? beacuse if all the philosophers pick fork with id then 
 they all forks are occupied and they can't pick fork (id+1)%5, so each of them are waiting to 
 pick the next fork and the system will be in a deadlock.

 A deadlock occurs when: 
Two or more threads are waiting for resources held by each other, and none can proceed.

A deadlock can happen only if all four of these conditions are true. 
 1. Mutual Exclusion : Resource cannot be shared.
 2. Hold and Wait: A thread holds one resource while waiting for another.
 3. No Preemption: Resources cannot be forcibly taken away.
 4. Circular Wait: A cycle exists
 
 
 How do we prevent it: 
 1. Resource Ordering: Always acquire resources in the same global order.
      int first = min(left, right);
      int second = max(left, right);

      forks[first].lock();
      forks[second].lock();

 2. One Philosopher Reverses Order: others pick left then right, one picks right then left.
 3. Limit the Number of Philosophers: limit the no. of Philosophers eating simultaneously.
     use semaphores.
 4. Try Lock: try_lock(); If second fork isn't available,release the first fork ,Retry later.
     forks[left].lock()
      if(!forks[right].try_lock()){
      forks[left].unlock();
      continue;
      }

      
 */