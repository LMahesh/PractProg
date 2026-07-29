#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

struct TaskQueue {
    std::mutex lock;
    bool done;
    unsigned int capacity;
    std::queue<std::string> buf;

    TaskQueue(int capacity) : capacity(capacity) {
        done = false;
    }
};

struct Emitter {
    TaskQueue* queue;
    std::vector<std::string> words;

    Emitter(TaskQueue* queue,
        std::vector<std::string> words)
        :
        queue(queue),
        words(words) {}
};

void producer_task(Emitter* emitter) {
    TaskQueue* queue = emitter->queue;

    for (unsigned int i = 0; i < emitter->words.size();) {
        queue->lock.lock();
        queue->buf.push(emitter->words[i++]);
        queue->lock.unlock();
    }

    //atomic_store_n(&queue->done, true, __ATOMIC_SEQ_CST);
}

void consumer_task(TaskQueue* queue) {
    for (;;) {
        queue->lock.lock();

        if (queue->done && queue->buf.empty()) {
           // queue->lock.unlock();
            break;
        }
        else if (queue->buf.size()) {
            std::cout << queue->buf.front() << std::endl;
            queue->buf.pop();
        }

        queue->lock.unlock();
    }
}

int main()
{
    std::vector<std::string> words{
       "apple", "banana", "cantaloupe",
       "strawberry", "grapefruit", "jackfruit",
       "cherry", "blueberry", "orange", "watermelon"
    };
    /*
    auto* queue = new TaskQueue(7);
    queue->done = false;
    auto* emitter = new Emitter(queue, words);
    std::thread consumer(consumer_task, queue);
    std::thread producer(producer_task, emitter);
    producer.join();
    consumer.join();
    delete queue;
    delete emitter;
    */
    //////////////////////////////////////////////////////////
    
    auto *queue1 = new TaskQueue(7);
    auto *emitter1 = new Emitter(queue1, words);
    std::thread consumer1(consumer_task, queue1);
    std::thread consumer2(consumer_task, queue1);
    std::thread producer1(producer_task, emitter1);
    producer1.join();
    consumer1.join();
    consumer2.join();
    delete queue1;
    delete emitter1;
}