#ifndef MY_QUEUE
#define MY_QUEUE

#include <iostream>


using namespace std;
 
template <typename T> class MyQueue {
private:
    T* ptr;
    int size;
    int head, tail;
 
public:
    MyQueue(int s);
    void print();
    void pushQueue(T elem);
    void popQueue();
};
 
template <typename T> MyQueue<T>::MyQueue(int s)
{
    ptr = new T[s];
    size = s;
    head = -1;
    tail = 0;
}
 
template <typename T> void MyQueue<T>::print()
{
    if (head < 0) return;
    for (int i = head; i >= tail; i--)
        cout << " " << *(ptr + i);
    cout << endl;
}

template<typename T>
void MyQueue<T>::pushQueue(T elem) {
    head++;
    *(ptr+head) = elem;
}

template<typename T> 
void MyQueue<T>::popQueue() {
    
    tail++;
}


#endif