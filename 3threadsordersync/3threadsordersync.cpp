/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <thread>
#include <fstream>
#include <mutex>
#include <condition_variable>

std::ofstream outfile("sample.txt");
int i = 0;
std::mutex mtx;
int arr[3] = { 0,1,1 };
std::condition_variable cv;
void func1(int id)
{
    std::cout << id << std::endl;
    //std::cout<<std::this_thread::get_id()<<std::endl;
    while (i < 100)
    {

        std::unique_lock<std::mutex>lock1(mtx);

        cv.wait(lock1, []() { return arr[0] == 0; });
        outfile << "thread id: " << id << std::endl;
        arr[0] = 1;
        arr[1] = 0;
        arr[2] = 1;
        lock1.unlock();

        i++;
        cv.notify_all();
    }
    //outfile.close();
}
void func2(int id)
{

    //std::cout<<std::this_thread::get_id()<<std::endl;
    std::cout << id << std::endl;
    while (i < 100)
    {
        std::unique_lock<std::mutex>lock1(mtx);

        cv.wait(lock1, []() { return arr[1] == 0; });
        outfile << "thread id: " << id << std::endl;
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 0;
        lock1.unlock();
        i++;

        cv.notify_all();
    }
}

void func3(int id)
{

    std::cout << id << std::endl;
    while (i < 100)
    {
        std::unique_lock<std::mutex>lock1(mtx);

        cv.wait(lock1, []() { return arr[2] == 0; });
        outfile << "thread id: " << id << std::endl;
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        lock1.unlock();

        i++;
        cv.notify_all();
    }

}

int main()
{
    std::cout << "Hello World" << std::endl;
    std::thread th1(func1, 1);
    std::thread th2(func2, 2);
    std::thread th3(func3, 3);

    th1.join();

    th2.join();

    th3.join();

    return 0;
}