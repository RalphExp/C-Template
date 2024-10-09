#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>

std::future<int> f;

int task() {
    for (int i = 0; i < 3; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}

void print_status(std::future_status& s) {
    if (s == std::future_status::deferred) {
        std::cout << "status: deferred" << std::endl;
    } else if (s == std::future_status::ready) {
        std::cout << "status: ready" << std::endl;
    } else {
        std::cout << "status: timeout" << std::endl;
    }
}

int main() {
    f = std::async(std::launch::async, task);
    std::future_status status = f.wait_for(std::chrono::seconds(0));

    while (status != std::future_status::ready) {
        print_status(status);
        // std::cout.flush();
        status = f.wait_for(std::chrono::milliseconds(100));
    }
    print_status(status);
    std::cout << std::endl;
}