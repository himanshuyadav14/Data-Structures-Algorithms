// void convertIntoSortedDll(TreeNode<int>* root, TreeNode<int>* &head){
//     //base case
//     if(root == NULL){
//         return;
//     }

//     convertIntoSortedDll(root->right,head);
//     root->right = head;
    
//     if(head!=NULL){
//         head->left = root;
//     }
    
//     head = root;

//     convertIntoSortedDll(root->left,head);
    
// }

// TreeNode<int>* mergeLL(TreeNode<int>* head1,TreeNode<int>* head2){

//     TreeNode<int>* head = NULL;
//     TreeNode<int>* tail = NULL;

//     while(head1!=NULL && head2!=NULL){
        
//         if(head1->data < head2->data){
            
//             if(head==NULL){
//                 head = head1;
//                 tail = head;
//                 head1 = head1->right;
//             }
//             else{
//                 tail->right = head1;
//                 head1->left = tail;
//                 tail = head1;
//                 head1 = head1->right;
//             }
//         }
//         else{
            
//             if(head==NULL){
//                 head = head2;
//                 tail = head;
//                 head2 = head2->right;
//             }
//             else{
//                 tail->right = head2;
//                 head2->left = tail;
//                 tail = head2;
//                 head2 = head2->right;
//             }
//         }
//     }

//     while(head1!=NULL){
//         tail->right = head1;
//         head1->left = tail;
//         tail = head1;
//         head1 = head1->right;
//     }

//     while(head2!=NULL){
//         tail->right = head2;
//         head2->left = tail;
//         tail = head2;
//         head2 = head2->right;
//     }

//     return head;
// }

// int countNodes(TreeNode<int>* head){
//     int cnt = 0;
//     TreeNode<int>* temp = head;
//     while(temp!=NULL){
//         cnt++;
//         temp = temp->right;
//     }
//     return cnt;

// }

// TreeNode<int>* sortedLLtoBST(TreeNode<int>* &head, int n){
//     //base case
//     if(n<=0 || head==NULL){
//         return NULL;
//     }

//     TreeNode<int>* leftAns = sortedLLtoBST(head,n/2);
    
//     TreeNode<int>* root = head;
//     root->left = leftAns;

//     head = head->right;

//     root->right = sortedLLtoBST(head,n-n/2-1);

//     return root;
// }


// TreeNode<int>* mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    
//     //step1: convert BST into sorted DLL : in-place
//     TreeNode<int>* head1 = NULL;
//     convertIntoSortedDll(root1,head1);
//     head1->left = NULL;

//     TreeNode<int>* head2 = NULL;
//     convertIntoSortedDll(root2,head2);
//     head2->left = NULL;

//     //step2: merge 2 sorted LL
//     TreeNode<int>* head = mergeLL(head1,head2);

//     //step3: convert sortedLL into BST
//     int n = countNodes(head);
//     TreeNode<int>* root = sortedLLtoBST(head,n);

//     return root;
// }