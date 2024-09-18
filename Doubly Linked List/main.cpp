#include <iostream>
using namespace std;

class DoublyLinkedList {

    struct Node
    {
        int data;
        Node* prev;
        Node* next;
        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;

public:

    DoublyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }


    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }


    void deleteNode(int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;

        while (temp != nullptr && temp->data != value)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Node with value " << value << " not found!" << endl;
            return;
        }

        if (temp == head)
        {
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
        }
        else
        {
            if (temp->next != nullptr)
            {
                temp->next->prev = temp->prev;
            }
            if (temp->prev != nullptr)
            {
                temp->prev->next = temp->next;
            }
        }
        delete temp;
    }


    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList one;

    one.insertAtBeginning(10);
    one.insertAtBeginning(20);
    one.insertAtEnd(30);
    one.insertAtEnd(40);

    cout << "Doubly Linked List: ";
    one.display();

    one.deleteNode(20);
    cout << "After deletion: ";
    one.display();

    one.deleteNode(50);

    return 0;
}
