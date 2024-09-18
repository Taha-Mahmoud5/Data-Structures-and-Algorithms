#include <iostream>
using namespace std;

template<typename T>
#define size 5

class CircularQueue
{
private:
    int front;
    int rear;
    T queue[5];

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear == front -1);
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    void enqueue(T value)
    {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
            rear++;

        queue[rear] = value;
    }

    int dequeue()
    {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        int data = queue[front];
        queue[front] = -1;

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
        return data;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Elements in Circular Queue are: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < size; i++)
            {
                cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    CircularQueue<int> one;

    one.enqueue(10);
    one.enqueue(20);
    one.enqueue(30);
    one.enqueue(40);
    one.enqueue(50);

    one.displayQueue();
    one.dequeue();
    one.displayQueue();

    one.enqueue(60);

    one.displayQueue();
    one.dequeue();
    one.displayQueue();

    return 0;
}
