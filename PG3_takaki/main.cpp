#include <stdio.h>
#include <thread>

volatile int current_thread = 1;

void printThread(int thread_id, const char* message) {

    while (current_thread != thread_id) {
    
        std::this_thread::yield();
    }

    printf("%s\n", message);

    current_thread++;
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
