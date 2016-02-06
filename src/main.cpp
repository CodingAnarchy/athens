#include <iostream>
#include <thread>
using namespace std;

void print_hello(){
  fprintf(stdout, "Hello, World!\n");
}

int main() {
    thread t1(print_hello);
    thread t2(print_hello);

    t1.join();
    t2.join();
    return 0;
}
