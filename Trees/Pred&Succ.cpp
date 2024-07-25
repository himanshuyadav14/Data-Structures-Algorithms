// TreeNode* minValue(TreeNode* root) {
//     TreeNode* temp = root;
//     while (temp && temp->left) 
//         temp = temp->left;
//     return temp;
// }

// TreeNode* maxValue(TreeNode* root) {
//     TreeNode* temp = root;
//     while (temp && temp->right) 
//         temp = temp->right;
//     return temp;
// }

// pair<int, int> predecessorSuccessor(TreeNode* root, int key) {
//     TreeNode* temp = root;
//     int pred = -1;
//     int succ = -1;

//     while (temp && temp->data != key) {
//         if(key < temp->data){
//             succ = temp->data; //potential successor
//             temp = temp->left;
//         }else{
//             pred = temp->data; //potential predecessor
//             temp = temp->right;
//         }
//     }

//     if(temp){
//         TreeNode* leftTree = temp->left;
//         TreeNode* rightTree = temp->right;

//         if(leftTree){
//             pred = maxValue(leftTree) ? maxValue(leftTree)->data : pred;
//         }

//         if(rightTree){
//             succ = minValue(rightTree) ? minValue(rightTree)->data : succ;
//         }
//     }

//     return {pred, succ};
// }
