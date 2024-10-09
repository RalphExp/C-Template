#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>

using namespace std;

int doSomething (char c) {
    // random-number generator (use c as seed to get different sequences)
    std::default_random_engine dre(c);
    std::uniform_int_distribution<int> id(10, 1000);

    // loop to print character after a random period of time
    for (int i = 0; i < 10; ++i) {
        auto t = chrono::milliseconds(id(dre));
        this_thread::sleep_for(t);
        std::cout << "[" << c << "]sleep for: " << t.count() << " ms" << std::endl;
    }
    return c;
}

int func1 () {
    return doSomething('.');
}

int func2 () {
    return doSomething('+');
}

int main() {
    std::cout << "starting func1() in background"
              << " and func2() in foreground:" << std::endl;

    // start func1() asynchronously (now or later or never):
    std::future<int> result1(std::async(func1));

    std::future<int> result2(std::async(func2)); // call func2() synchronously (here and now)

    std::cout << "waiting for the result" << std::endl;

    // print result (wait for func1() to finish and add its result to result2
    int result = result1.get() + result2.get();
    std::cout << std::endl << "result of func1()+func2(): " << result << std::endl;
}