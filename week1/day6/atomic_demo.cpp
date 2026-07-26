#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int unsafe_counter = 0;
atomic<int> atomic_counter{0};

void add_unsafe(int loop_count) {
    for (int i = 0; i < loop_count; ++i) {
        unsafe_counter++;
    }
}

void add_atomic(int loop_count) {
    for (int i = 0; i < loop_count; ++i) {
        atomic_counter++;
    }
}

int main() {
    const int thread_count = 4;
    const int loop_count = 100000;

    vector<thread> threads;

    for (int i = 0; i < thread_count; ++i) {
        threads.emplace_back(add_unsafe, loop_count);
    }

    for (auto& t : threads) {
        t.join();
    }

    cout << "unsafe_counter = " << unsafe_counter << endl;
    cout << "expected       = " << thread_count * loop_count << endl;

    threads.clear();

    for (int i = 0; i < thread_count; ++i) {
        threads.emplace_back(add_atomic, loop_count);
    }

    for (auto& t : threads) {
        t.join();
    }

    cout << "atomic_counter = " << atomic_counter.load() << endl;
    cout << "expected       = " << thread_count * loop_count << endl;

    return 0;
}
