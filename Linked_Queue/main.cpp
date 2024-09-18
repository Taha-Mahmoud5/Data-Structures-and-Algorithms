#include <iostream>
using namespace std;

template<typename T> // to use all type of VAR.

class LinkedQueue {

    struct Node
    {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    LinkedQueue() : front(nullptr), rear(nullptr) {}


    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(T value)
    {
        Node* newNode = new Node(value);
        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
    }

    int peekFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main() {
    LinkedQueue<int> queue;


    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);


    cout << "Queue contents: ";
    queue.display();


    cout << "Front element: " << queue.peekFront() << endl;


    queue.dequeue();
    cout << "After dequeue, queue contents: ";
    queue.display();
    cout << "Front element: " << queue.peekFront() << endl;

    return 0;
}
