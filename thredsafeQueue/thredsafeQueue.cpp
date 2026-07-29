// thredsafeQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

template<typename T>
class TSQuee
{
private:
    //T dat;
    queue<T>sque;
    std::mutex mtx;
    std::condition_variable cv;
public:

    void push(T dat)
    {
        std::unique_lock<std::mutex> lock1(mtx);
        sque.push(dat);
        cv.notify_one();
    }

    T Pop()
    {
        std::unique_lock<std::mutex> lock1(mtx);
        cv.wait(lock1, [this]() {return !sque.empty(); });
        T dat = sque.front();
        sque.pop();
        return dat;
    }

    //T get()
    //{
      //T dat = 
    //}
};

int main()
{
    std::cout << "Hello World!\n";


    TSQuee<int> Tsq;
    Tsq.push(1);
    Tsq.push(2);
    Tsq.push(3);

    std::cout << "Pop Quedat: " << Tsq.Pop() << std::endl;
    std::cout << "Pop Quedat: " << Tsq.Pop() << std::endl;
    std::cout << "Pop Quedat: " << Tsq.Pop() << std::endl;
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
