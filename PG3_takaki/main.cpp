#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int current_thread = 1;

void printThread(int thread_id, const std::string& message) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [thread_id]() { return current_thread == thread_id; });

    std::cout << message << std::endl;

    current_thread++;
    cv.notify_all();
}

int main() {
   
    std::thread t1(printThread, 1, "thread 1");
    std::thread t2(printThread, 2, "thread 2");
    std::thread t3(printThread, 3, "thread 3");

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
