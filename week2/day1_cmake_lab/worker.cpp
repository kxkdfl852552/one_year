#include "worker.h"

#include <iostream>

#include <thread>

void run_worker(){
    std::thread t([]{
        std::cout << "worker thread running" << std::endl;
    });
    t.join();
}