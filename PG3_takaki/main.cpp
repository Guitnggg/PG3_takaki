#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<int> current_thread(1);

void PrintThread(int thread_id) {

    while (current_thread.load() != thread_id) {
        this_thread::yield(); 
    }

    cout << "thread " << thread_id << endl;

    current_thread++;
}

int main() {

    thread t1(PrintThread, 1);
    thread t2(PrintThread, 2);
    thread t3(PrintThread, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
