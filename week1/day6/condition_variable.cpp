#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

queue<int> tasks;
mutex mtx;
condition_variable cv;
bool finished = false;

void producer() {
    for (int i = 0; i < 5; ++i) {
        {
            lock_guard<mutex> lock(mtx);
            tasks.push(i);
        }

        cv.notify_one();
    }

    {
        lock_guard<mutex> lock(mtx);
        finished = true;
    }

    cv.notify_all();
}

void consumer() {
    while (true) {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [] {
            return !tasks.empty() || finished;
        });

        if (tasks.empty() && finished) {
            break;
        }

        int task = tasks.front();
        tasks.pop();

        lock.unlock();

        cout << "process task: " << task << endl;
    }
}

int main() {
    thread producer_thread(producer);
    thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    return 0;
}
