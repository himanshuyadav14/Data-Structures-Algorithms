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

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // NULL act as seprator for printing endl
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

// LNR
void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    // left
    inOrderTraversal(root->left);

    // print
    cout << root->data << " ";

    // right
    inOrderTraversal(root->right);
}

// NLR
void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    // print
    cout << root->data << " ";

    // left
    preOrderTraversal(root->left);

    // right
    preOrderTraversal(root->right);
}

// LRN
void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    // left
    postOrderTraversal(root->left);

    // right
    postOrderTraversal(root->right);

    // print
    cout << root->data << " ";
}

void buildFromLevelOrderTraversal(Node* &root)
{
    queue<Node *> q;

    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;

    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;

    buildFromLevelOrderTraversal(root);
    levelOrderTraversal(root);
    // // creating a Tree
    // root = buildTree(root);
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // // level order traversal
    // cout << "Printing the level order traversal" << endl;
    // levelOrderTraversal(root);
    // cout << endl;

    // // inOrder traversal
    // cout << "Printing the  inOrder traversal" << endl;
    // inOrderTraversal(root);
    // cout << endl;

    // // preOrder traversal
    // cout << "Printing the  preOrder traversal" << endl;
    // preOrderTraversal(root);
    // cout << endl;

    // // postOrder traversal
    // cout << "Printing the  postOrder traversal" << endl;
    // postOrderTraversal(root);

    return 0;
}