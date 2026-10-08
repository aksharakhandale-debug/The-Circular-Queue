#include <iostream>

class CircularQueue {
private:
    int *queue;
    int front;
    int rear;
    int capacity;

public:
    CircularQueue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() {
        return ((rear + 1) % capacity == front);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int data) {
        if (isFull()) {
            std::cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = data;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow\n";
            return -1;
        }
        int data = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return data;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is Empty\n";
            return;
        }
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                std::cout << queue[i] << " ";
            }
        } else {
            for (int i = front; i < capacity; i++) {
                std::cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                std::cout << queue[i] << " ";
            }
        }
        std::cout << "\n";
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.display();

    cq.dequeue();
    cq.display();

    return 0;
}
