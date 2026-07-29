// Testpractprg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int i = 0;
void printodd()
{
    for (; i <= 100;)
    {

       // std::unique_lock<std::mutex> locker(mu);
        //cond.wait(locker, []() { return (count % 2 == 1); });

        std::unique_lock<std::mutex>lock1(mtx);

        cv.wait(lock1, []() {return(i % 2 == 1); });
        std::cout << "from odd:"<<i << " "; i = i + 1;
        lock1.unlock();
        cv.notify_all();
    }
}
void printevn()
{
    for (; i <= 100;)
    {

        // std::unique_lock<std::mutex> locker(mu);
         //cond.wait(locker, []() { return (count % 2 == 1); });

        std::unique_lock<std::mutex>lock2(mtx);

        cv.wait(lock2, []() {return (i % 2 == 0); });
        std::cout << "from even:" << i << " ";
        i = i + 1;
        lock2.unlock();
        cv.notify_all();
    }
}

int main()
{
    std::cout << "Hello World!\n";

    std::thread th1(printevn);
    std::thread th2(printodd);
    th1.join();
    th2.join();

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
