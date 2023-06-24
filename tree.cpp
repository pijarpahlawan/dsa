#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    else
    {
        cout << "Duplicate data: " << data << "\n";
    }
    return root;
}

bool searchNode(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data < root->data)
    {
        return searchNode(root->left, data);
    }
    else
    {
        return searchNode(root->right, data);
    }
}

int findMin(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty\n";
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    return findMin(root->left);
}

int findMax(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty\n";
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    return findMax(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    int menu = 0;
    int insertAgain = 1;

    while (menu != 9)
    {
        cout << "1. Insert\n"
             << endl;
        cout << "2. Search\n"
             << endl;
        cout << "3. Find Min\n"
             << endl;
        cout << "4. Find Max\n"
             << endl;
        cout << "5. Preorder traversal\n"
             << endl;
        cout << "6. Inorder traversal\n"
             << endl;
        cout << "7. Postorder traversal\n"
             << endl;
        cout << "8. Exit\n"
             << endl;
        cout << "Enter your choice: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            int data;
            while (insertAgain)
            {
                cout << "Enter data to insert: ";
                cin >> data;
                root = insertNode(root, data);
                cout << "Inserted\n";
                cout << "Insert again? (1/0): ";
                cin >> insertAgain;
            }
            break;
        case 2:
            cout << "Enter data to search: ";
            cin >> data;
            if (searchNode(root, data))
            {
                cout << "Found\n";
            }
            else
            {
                cout << "Not found\n";
            }
            break;
        case 3:
            cout << "Min: " << findMin(root) << "\n";
            break;
        case 4:
            cout << "Max: " << findMax(root) << "\n";
            break;
        case 5:
            cout << "Preorder: \n";
            preOrder(root);
            cout << "\n";
            break;
        case 6:
            cout << "Inorder: \n";
            inOrder(root);
            cout << "\n";
            break;
        case 7:
            cout << "Postorder: \n";
            postOrder(root);
            cout << "\n";
            break;
        case 8:
            cout << "Exiting...\n";
            return 0;
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }

        cin.get();
        cin.ignore();

        system("clear");
    }

    return 0;
}