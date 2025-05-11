#include <iostream>
#include <exception>
using namespace std;

class OverflowQueueError : public exception {};
class UnderflowQueueError : public exception {};

template <typename ElementType>
class StaticQueue {
    ElementType* storage;
    int capacity;
    int head, tail, itemCount;

public:
    StaticQueue(int maxSize) : capacity(maxSize), head(0), tail(0), itemCount(0) {
        storage = new ElementType[capacity];
    }

    void push(ElementType newItem) {
        if (itemCount == capacity) {
            throw OverflowQueueError();
        }
        storage[tail] = newItem;
        tail = (tail + 1) % capacity;
        itemCount++;
    }

    ElementType pop() {
        if (itemCount == 0) {
            throw UnderflowQueueError();
        }
        ElementType removedItem = storage[head];
        head = (head + 1) % capacity;
        itemCount--;
        return removedItem;
    }

    ~StaticQueue() {
        delete[] storage;
    }
};

int main() {
    StaticQueue<int> myQueue(1);

    try {
        myQueue.push(5);
        cout << "Attempting to enqueue to a full queue..." << endl;
        myQueue.push(10);
    } catch (const OverflowQueueError& e) {
        cout << "Caught QueueOverflowException - what(): " << e.what() << endl;
    }

    StaticQueue<int> emptyQueue(1);
    try {
        cout << "Attempting to dequeue from an empty queue..." << endl;
        emptyQueue.pop();
    } catch (const UnderflowQueueError& e) {
        cout << "Caught QueueUnderflowException - what(): " << e.what() << endl;
    }

    return 0;
}