// Creation of Binary Trees
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void inorderMorrisTraversal(Node *root)
{
    Node *curr = root;
    while (curr)
    {
        if (curr->left)
        {
            Node *pred = curr->left;
            while (pred->right && pred->right != curr)
                pred = pred->right;
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
        else
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

void preorderMorrisTraversal(Node *root)
{
    Node *curr = root;
    while (curr)
    {
        
        if (curr->left)
        {
            //Link creation
            Node *pred = curr->left;
            while (pred->right && pred->right != curr) pred = pred->right;
            if (pred->right == NULL)
            {
                pred->right = curr;
                cout << curr->data << " ";
                curr = curr->left;
            }
            else
            {
                //Link deletion
                pred->right = NULL;
                curr = curr->right;
            }
        }
        else
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

// Morris Traversal inorder ,preorder ,postorder
int main()
{
    Node *root = NULL;
    root = buildTree(root);

    cout << "Printing the Inorder Morris Traversal" << endl;
    inorderMorrisTraversal(root);
    cout << endl;

    cout << "Printing the Preorder Morris Traversal" << endl;
    preorderMorrisTraversal(root);
    cout << endl;
}