#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build the binary tree
Node *buildTree(Node *root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    // If the input is -1, it indicates a NULL node
    if (data == -1)
        return NULL;

    // Create a new node with the input data
    root = new Node(data);

    // Recursively build the left subtree
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    // Recursively build the right subtree
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// Function for iterative inorder traversal
void iterativeInorderTraversal(Node* root) {
    stack<Node*> st;

    while (root || !st.empty()) {
        if (root) {
            st.push(root);
            root = root->left;
        } else {
            root = st.top();
            st.pop();
            cout << root->data << " ";
            root = root->right;
        }
    }
}

// Function for iterative preorder traversal
void iterativePreorderTraversal(Node* root) {
    stack<Node*> st;

    while (root || !st.empty()) {
        if (root) {
            cout << root->data << " ";
            st.push(root);
            root = root->left;
        } else {
            root = st.top()->right;
            st.pop();
        }
    }
}

//using 2 stacks
void iterativePostorderTraversal1(Node* root) {
    stack<Node*> st1, st2;

    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();

        st2.push(root);

        if(root->left) st1.push(root->left);
        if(root->right) st1.push(root->right);
    }

    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}

//using 1 stack
void iterativePostorderTraversal2(Node* root) {
    stack<Node*> st;
    Node* lastVisitedNode = NULL;

    while(root || !st.empty()){
        if(root){
            st.push(root);
            root = root->left;
        }else{
            Node* temp = st.top();
            if(temp->right != NULL && temp->right != lastVisitedNode){
                root = temp->right;
            }else{
                cout << temp->data << " ";
                lastVisitedNode = temp;
                st.pop();
            }
        }
    }
}

int main() {
    Node* root = NULL;

    // Build the tree
    root = buildTree(root);

    // Perform iterative inorder traversal
    cout << "Printing Iterative Inorder Traversal" << endl;
    iterativeInorderTraversal(root);
    cout << endl;

    // Perform iterative preorder traversal
    cout << "Printing Iterative Preorder Traversal" << endl;
    iterativePreorderTraversal(root);
    cout << endl;

    // Perform iterative postorder traversal
    cout << "Printing Iterative Postorder Traversal" << endl;
    iterativePostorderTraversal2(root);
    cout << endl;

    return 0;
}
