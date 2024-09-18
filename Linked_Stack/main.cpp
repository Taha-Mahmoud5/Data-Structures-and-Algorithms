#include <iostream>
using namespace std;

class LinkedStack {

    struct Node
    {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* top;

public:
    LinkedStack() : top(nullptr) {}


    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }


    int peek() {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }


    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {

    LinkedStack stack;


    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(400);

    cout << "Stack contents: ";
    stack.display();


    cout << "Top element: " << stack.peek() << endl;


    stack.pop();
    cout << "After pop, stack contents: ";
    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    return 0;
}
