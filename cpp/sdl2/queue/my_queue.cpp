#include"include/my_queue.hpp"

int main(int argc, char ** argv) {
    MyQueue<int> my_queue = MyQueue<int>(10);

    my_queue.pushQueue(10);
    my_queue.pushQueue(10);
    my_queue.pushQueue(10);
    my_queue.pushQueue(30);
    my_queue.popQueue();
    my_queue.print();

    
}