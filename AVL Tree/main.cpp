#include <iostream>
using namespace std;

template<typename T>
class AVLTree
{
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        int height;

        Node(T value)
        {
            data = value;
            left = right = nullptr;
            height = 1;
        }
    };

    Node* root;

    int height(Node* node)
    {
        return node ? node->height : 0; // if
    }

    int getBalanceFactor(Node* node)
    {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x)
    {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
             node->right = insert(node->right, value);
        }
        else
            return node;

        node->height = max(height(node->left), height(node->right)) + 1;

        int balance = getBalanceFactor(node);

        if (balance > 1 && value < node->left->data)
        {
            return rightRotate(node);
        }


        if (balance < -1 && value > node->right->data)
        {
            return leftRotate(node);
        }

        if (balance > 1 && value > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* findMin(Node* node)
    {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    Node* deleteNode(Node* root, int value)
    {
        if (root == nullptr)
            return root;

        if (value < root->data)
            root->left = deleteNode(root->left, value);
        else if (value > root->data)
            root->right = deleteNode(root->right, value);
        else {
            if ((root->left == nullptr) || (root->right == nullptr))
            {
                Node* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;

                delete temp;
            }
            else
            {
                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == nullptr)
            return root;

        root->height = max(height(root->left), height(root->right)) + 1;

        int balance = getBalanceFactor(root);

        if (balance > 1 && getBalanceFactor(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalanceFactor(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalanceFactor(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalanceFactor(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inOrderTraversal(Node* node)
     {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = insert(root, value);
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
};

int main() {
    AVLTree<int> AVL;
    int choice, value;

    while (true) {
        cout << "\n  AVL Tree.\n";
        cout << "1. Insert a value\n";
        cout << "2. Delete a value\n";
        cout << "3. In-order Traversal\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                AVL.insert(value);
                cout << "Value inserted.\n";
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                AVL.deleteNode(value);
                cout << "Value deleted.\n";
                break;
            case 3:
                cout << "In-order Traversal: ";
                AVL.inOrderTraversal();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
