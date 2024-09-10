#include <deque>
#include <iostream>

using namespace std;

int main()
{
    // Enter your code here
    std::deque<int> deq;
    int front = 1;
    int x = 0;

    while ( x!= 0) {
        cin >> x;
        front==1 ? deq.push_back(x) : deq.push_front(x);
        front *= -1;
    }

    for (int v : deq) {
        std::cout <<v << std::endl;
    }
    return 0;
}
