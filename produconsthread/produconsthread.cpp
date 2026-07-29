// produconsthread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <fstream>
#include <condition_variable>
#include <string>
#include <mutex>

std::ofstream data_file("shared_data.txt");
std::queue<int>data_que;
std::mutex mtx;
std::condition_variable cv;
bool producer_done = false;

void producer()
{
    for (int i = 1; i <= 20; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        {
            std::lock_guard<std::mutex>lock1(mtx);
            if (data_file.is_open())
            {
                data_file << i;
                data_file.flush();
            }
            data_que.push(i);
            std::cout << "producer produce and wrot to file: " << i << std::endl;

        }
        cv.notify_one();
    }
    {
        std::lock_guard<std::mutex>lock(mtx);
        producer_done = true;

    }
    cv.notify_all();
}

void consumer(int id)
{

    while (true)
    {
        int value = 0;
        {
            std::unique_lock<std::mutex>lock(mtx);
            cv.wait(lock, []() {return !data_que.empty() || producer_done; });
            //cv.wait(lock, [] { return !data_queue.empty() || producer_done; });
            if (data_que.empty() && producer_done)
            {
                break;
            }
            value = data_que.front();
            data_que.pop();
        }
        std::cout << "consumer id: " << id << "consumed data: " << value << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(180));

    }
    std::cout << "----consumer id: " << id << " exited--------" << std::endl;
}

int main()
{
    std::cout << "Hello World!\n"<<std::endl;
    std::vector<std::thread>consumerlist;
    std::thread prod_thread(producer);
    for (int i = 1; i <=3; i++)
        consumerlist.push_back(std::thread(consumer, i));

    prod_thread.join();

    for (auto& consth : consumerlist)
        consth.join();
    if (data_file.is_open())
    {
        data_file.close();
    }
}
