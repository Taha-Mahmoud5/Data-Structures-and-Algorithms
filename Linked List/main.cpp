#include <iostream>
using namespace std;

template<typename T>

class Linked_List
{
private:
    struct Node
    {
        T data;
        Node* next;

        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    Linked_List() : head(nullptr) {}

    void add_first(T val)
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void add_end(T val)
    {
        Node* newNode = new Node(val);
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
        }
    }

    void insertAfter(int key, T val)
    {
        Node* temp = head;
        while (temp != nullptr && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp != nullptr)
        {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            cout << "Element " << key << " not found." << endl;
        }
    }

    void delete_first()
    {
        if (head == nullptr)
            return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void delete_End()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void delete_Node(int val)
    {
        if (head == nullptr)
            return;

        if (head->data == val)
        {
            delete_first();
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val)
        {
            temp = temp->next;
        }

        if (temp->next != nullptr)
        {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    void display() const
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void reverse()
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    Node* search(T val)
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    ~Linked_List()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main()
{
    Linked_List <int> list;

    list.add_first(0);
    list.add_first(10);
    list.add_first(20);
    list.add_first(30);
    list.add_first(40);

    cout << "Original List : ";
    list.display();

    list.reverse();

    cout << "Reversed List : ";
    list.display();

    int searchValue;
    cout << "Enter value to search : ";
    cin >> searchValue;

    if (list.search(searchValue) != nullptr)
        cout << "Value " << searchValue << " found in the list.\n";
    else
        cout << "Value " << searchValue << " not found in the list.\n";

    return 0;
}
