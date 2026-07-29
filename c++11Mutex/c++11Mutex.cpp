// c++11Mutex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
mutex mtx;
condition_variable cv;

bool Data_Ready = false;

void consumer()
{
    unique_lock<mutex>lock1(mtx); //lock
    cv.wait(lock1, [] {return Data_Ready; });

    std::cout << "Data Ready" << std::endl;

}

void productive()
{
    //this_thread::sleep_for(chrono::seconds (10));
    lock_guard<mutex>lock1(mtx); //unlock
    Data_Ready = true;
    std::cout << "Data Produced" << std::endl;

    cv.notify_one();

    

}

int main()
{
    thread consumer_Thread(consumer);
    thread produc_Thread(productive);
    consumer_Thread.join();
    produc_Thread.join();
    std::cout << "Hello World!\n";
}

*/
/*
#include<iostream>
#include<thread>
#include <mutex>
#include<condition_variable>

using namespace std;
mutex mtx;
condition_variable cv;

int i = 0;
void waits()
{
    unique_lock<mutex>lock1(mtx);
    cv.wait(lock1, [] {return i == 1; });
    std::cout << "finished awaiting" << std::endl;

}

void signals()
{
   this_thread::sleep_for(chrono::seconds(1));
   {
       lock_guard<mutex>lock1(mtx);
   }
   std::cout << "Notify to all" << std::endl;
   cv.notify_all();

   i = 1;
   this_thread::sleep_for(chrono::seconds(1));
   {
       lock_guard<mutex>lock1(mtx);
   }
   std::cout << "Notifyall once again" << std::endl;
   cv.notify_all();
}

void main()
{

    thread th1(waits), th2(waits), th3(waits), th4(signals);
    th1.join();
    th2.join();
    th3.join();
    th4.join();
}



*/

/*
// Online C++ compiler to run C++ program online
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex mutx;
condition_variable cv;
bool Data_Ready = false;


void producer()
{
    this_thread::sleep_for(chrono::seconds(10));
    std::lock_guard<mutex>lck1(mutx);
    Data_Ready = true;
    std::cout << "Data is produce";
    cv.notify_one();

}
void consumer()
{
    unique_lock<mutex>lock1(mutx);
    cv.wait(lock1, [] {return Data_Ready; });

    std::cout << "Data Ready" << std::endl;
}



int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    thread th(consumer);
    thread th1(producer);
    th.join();
    th1.join();
    return 0;
}


*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mu;
std::condition_variable cond;
int count = 1;

void PrintOdd()
{
    for (; count < 100;)
    {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, []() { return (count % 2 == 1); });
        std::cout << "From Odd:    " << count << std::endl;
        count++;
        locker.unlock();
        cond.notify_all();
    }

}


void PrintEven()
{
    for (; count < 100;)
    {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, []() { return (count % 2 == 0); });
        std::cout << "From Even: " << count << std::endl;
        count++;
        locker.unlock();
        cond.notify_all();
    }
}

int main()
{
    std::thread t1(PrintOdd);
    std::thread t2(PrintEven);
    t1.join();
    t2.join();
    return 0;
}
