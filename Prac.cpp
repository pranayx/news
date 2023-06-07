#include <iostream>
using namespace std;

struct Node
{
    int key;
    string value;
    int height;
    Node* left;
    Node* right;

    Node(int k, const string& v) : key(k), value(v), height(1), left(nullptr), right(nullptr) {}
};

int height(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

int balanceFactor(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

void updateHeight(Node* node)
{
    node->height = 1 + max(height(node->left), height(node->right));
}

Node* rotateLeft(Node* node)
{
    cout<<"------LL Rotation Applied-------"<< endl;

    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

Node* rotateRight(Node* node)
{
    cout<<"------RR Rotation Applied-------"<< endl;

    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

Node* rotateLeftRight(Node* node)
{
    cout<<"------RL Rotation Applied-------"<< endl;

    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

Node* rotateRightLeft(Node* node)
{
    cout<<"------LR Rotation Applied-------"<< endl;

    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

Node* balance(Node* node)
{
    if (balanceFactor(node) == 2)
    {
        if (balanceFactor(node->left) < 0)
        {
            node = rotateLeftRight(node);
        }
        else
        {
            node = rotateRight(node);
        }
    }
    else if (balanceFactor(node) == -2)
    {
        if (balanceFactor(node->right) > 0)
        {
            node = rotateRightLeft(node);
        }
        else
        {
            node = rotateLeft(node);
        }
    }
    updateHeight(node);
    return node;
}

Node* insert(Node* node, int key, const string& value)
{
    if (node == nullptr)
    {
        return new Node(key, value);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key, value);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key, value);
    }
    else
    {
        node->value = value; // key already exists, update value
        return node;
    }
    return balance(node);
}

bool search(Node* node, int key)
{
    if (node == nullptr)
    {
        return false;
    }
    if (key < node->key)
    {
        return search(node->left, key);
    }
    else if (key > node->key)
    {
        return search(node->right, key);
    }
    else
    {
        return true;
    }
}

void inorderTraversal(Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    inorderTraversal(node->left);
    cout << node->key << ": " << node->value << " ";
    inorderTraversal(node->right);
}

void levelTraversal(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear)
    {
        Node* node = queue[front++];
        cout << node->key << ": " << node->value << " ";
        if (node->left != nullptr)
        {
            queue[rear++] = node->left;
        }
        if (node->right != nullptr)
        {
            queue[rear++] = node->right;
        }
    }
}

int main()
{
	int key;
	string value;

    Node* root = NULL;
    int choice = 0;

    do
    {
        cout << "Menu" << endl;
        cout << "1. Insert key-value pair" << endl;
        cout << "2. Search key" << endl;
        cout << "3. Level order traversal" << endl;
        cout << "4. Inorder traversal" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:


                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                root = insert(root, key, value);
                cout << "Inserted key-value pair: " << key << ": " << value << endl;
                break;

            case 2:

                cout << "Enter key to search: ";
                cin >> key;
                if (search(root, key))
                {
                    cout << "Key found!" << endl;
                }
                else
                {
                    cout << "Key not found." << endl;
                }
                break;

        case 3:
                cout << "Level order traversal: ";
                levelTraversal(root);
                cout << endl;
                break;


            case 4:

                cout << "Inorder traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;

            case 5:
                cout << "Quitting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}