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
        left = NULL;
        right = NULL;
    }
};

// level order traversal
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

// Function for creating a BST
Node *insertIntoBST(Node *root, int data)
{
    if (!root)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

// Function for take Input stream for creating a BST
void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Search in a BST  (Recursively)
//  class Solution {
//  public:
//      TreeNode* searchBST(TreeNode* root, int val) {
//          //Base case
//          if(!root) return NULL;
//          if(root->val == val) return root;

//         if(val < root->val) return searchBST(root->left,val);
//         else return searchBST(root->right, val);
//     }
// };

// Itervatively
//  class Solution {
//  public:
//  //In skewed Tree this space complexity will be o(n) so we have to solve it iteratively also
//      TreeNode* searchBST(TreeNode* root, int val) {
//          while(root){
//              if(root->val == val) return root;

//             if(val < root->val) root = root->left;
//             else root = root->right;
//         }
//         return NULL;
//     }
// };

// Min/Max value in BST
Node *minValue(Node *root)
{
    Node *temp = root;
    while (temp->left)
        temp = temp->left;
    return temp;
}

Node *maxValue(Node *root)
{
    Node *temp = root;
    while (temp->right)
        temp = temp->right;
    return temp;
}

// Deletion in BST
Node *deleteFromBST(Node *root, int val)
{
    // base case
    if (!root)
        return NULL;

    if (root->data == val)
    {

        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        //left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if (val < root->data)
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

// Time complexity : O(logn)
int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST " << endl;
    takeInput(root);

    // Perform Level order traversal
    cout << "Printing Level Order Traversal" << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Minimum value in BST is " << minValue(root)->data << endl;
    cout << "Maximum value in BST is " << maxValue(root)->data << endl;

    root = deleteFromBST(root,50);

    // Perform Level order traversal
    cout << "Printing Level Order Traversal" << endl;
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}