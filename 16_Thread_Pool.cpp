// Thread Pool
/* 
 A group of many threads each thread performs some task, completes it and then 
 gets a new task. Instead of creating a new Thread everytime we are just creating
 some threads in the beginning itself and then use them only.
*/

#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>
#include<bits/stdc++.h>
using namespace std;

class ThreadPool{
    public:
    vector<thread>workers;
    queue<function<void()>>tasks;
    mutex m;
    condition_variable cv;
    
    ThreadPool(int n){
       for(int i = 0; i<n; i++){
          //workers.emplace_back(&ThreadPool::Worker, this);
          workers.emplace_back( thread(&ThreadPool::Worker, this));
       }
    }
    void Worker(){
    while(true){
        function<void()>task;
        {
            unique_lock<mutex>lock(m);
            cv.wait(lock, [&]{return !tasks.empty();});
            task = move(tasks.front());
            tasks.pop();
        }
        task();
    }
      }
    
    void enqueue(function<void()>task){
         {
            lock_guard<mutex>lock(m);
            tasks.push(move(task));
         }
         cv.notify_one();
    }
    
};

