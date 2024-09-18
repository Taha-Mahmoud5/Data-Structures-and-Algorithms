#include <iostream>
using namespace std;

template <typename T>

class BinarySearchTree {
private:
    struct Node
    {
        T data;
        Node* left;
        Node* right;

        Node(T value)
        {
            data = value;
            left = right = nullptr;
        }
    };

    Node* root;

    Node* insert(Node* node, T value) {
        if (node == nullptr)
        {
            return new Node(value);
        }
        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else
        {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool search(Node* node, T value)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (node->data == value)
        {
            return true;
        }
         else if (value < node->data)
        {
            return search(node->left, value);
        }
        else
        {
            return search(node->right, value);
        }
    }

    Node* findMin(Node* node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, T value)
    {
        if (node == nullptr) return node;

        if (value < node->data)
        {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deleteNode(node->right, value);
        }
        else {
            if (node->left == nullptr)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void inOrderTraversal(Node* node)
    {
        if (node != nullptr)
        {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    void preOrderTraversal(Node* node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    void postOrderTraversal(Node* node)
    {
        if (node != nullptr)
        {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->data << " ";
        }
    }

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    bool search(int value)
    {
        return search(root, value);
    }

    void deleteNode(int value)
    {
        root = deleteNode(root, value);
    }

    void inOrderTraversal()
    {
        inOrderTraversal(root);
        cout << "\n";
    }

    void preOrderTraversal()
    {
        preOrderTraversal(root);
        cout << "\n";
    }

    void postOrderTraversal()
    {
        postOrderTraversal(root);
        cout << "\n";
    }
};

int main() {
    BinarySearchTree<int>BST;
    int choice, value;

    while (true) {
        cout << "\n--- Binary Search Tree ---\n";
        cout << "1. Insert a value\n";
        cout << "2. Delete a value\n";
        cout << "3. Search for a value\n";
        cout << "4. In-order Traversal\n";
        cout << "5. Pre-order Traversal\n";
        cout << "6. Post-order Traversal\n";
        cout << "7. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                BST.insert(value);
                cout << "Value inserted.\n";
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                BST.deleteNode(value);
                cout << "Value deleted.\n";
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (BST.search(value))
                    cout << "Value found in the tree.\n";
                else
                    cout << "Value not found in the tree.\n";
                break;
            case 4:
                cout << "In-order Traversal: ";
                BST.inOrderTraversal();
                break;
            case 5:
                cout << "Pre-order Traversal: ";
                BST.preOrderTraversal();
                break;
            case 6:
                cout << "Post-order Traversal: ";
                BST.postOrderTraversal();
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
