// #include <bits/stdc++.h>
// using namespace std;

// class TrieNode {
// public:
//     char data;
//     TrieNode* children[26];
//     bool isTerminal;
//     int wordCount;

//     TrieNode(char ch) {
//         data = ch;
//         for (int i = 0; i < 26; i++) children[i] = NULL;
//         isTerminal = false;
//         wordCount = 0;
//     }
// };

// class Trie {
// public:
//     TrieNode* root;

//     Trie() {
//         root = new TrieNode('\0');
//     }

//     void insertUtil(TrieNode* root, const string& word) {
//         // Base case
//         if (word.length() == 0) {
//             root->isTerminal = true;
//             root->wordCount++;
//             return;
//         }

//         int index = word[0] - 'a';
//         TrieNode* child;

//         if (root->children[index] != NULL) {
//             child = root->children[index];
//         } else {
//             child = new TrieNode(word[0]);
//             root->children[index] = child;
//         }

//         insertUtil(child, word.substr(1));
//     }

//     void insert(string &word) {
//         insertUtil(root, word);
//     }

//     int countWordsEqualToUtil(TrieNode* root, const string& word) {
//         // Base case
//         if (word.length() == 0) return root->isTerminal ? root->wordCount : 0;

//         int index = word[0] - 'a';
//         TrieNode* child;

//         if (root->children[index] != NULL) {
//             child = root->children[index];
//             return countWordsEqualToUtil(child, word.substr(1));
//         } else {
//             return 0;
//         }
//     }

//     int countWordsEqualTo(string &word) {
//         return countWordsEqualToUtil(root, word);
//     }

//     int countAllWords(TrieNode* root) {
//         int count = root->wordCount;

//         for (int i = 0; i < 26; i++) {
//             if (root->children[i] != NULL) {
//                 count += countAllWords(root->children[i]);
//             }
//         }

//         return count;
//     }

//     int countWordsStartingWithUtil(TrieNode* root, const string& word) {
//         // Base case
//         if (word.length() == 0) return countAllWords(root);

//         int index = word[0] - 'a';
//         TrieNode* child;

//         if (root->children[index] != NULL) {
//             child = root->children[index];
//             return countWordsStartingWithUtil(child, word.substr(1));
//         } else {
//             return 0;
//         }
//     }

//     int countWordsStartingWith(string &word) {
//         return countWordsStartingWithUtil(root, word);
//     }

//     bool eraseUtil(TrieNode* root, const string& word) {
//         // Base case
//         if (word.length() == 0) {
//             if (root->isTerminal) {
//                 root->wordCount--;
//                 if (root->wordCount == 0) {
//                     root->isTerminal = false;
//                 }
//             }
//             return root->wordCount == 0 && allChildrenNull(root);
//         }

//         int index = word[0] - 'a';
//         TrieNode* child;

//         if (root->children[index] != NULL) {
//             child = root->children[index];
//             bool shouldDeleteChild = eraseUtil(child, word.substr(1));

//             if (shouldDeleteChild) {
//                 delete child;
//                 root->children[index] = NULL;

//                 return !root->isTerminal && allChildrenNull(root);
//             }
//         }

//         return false;
//     }

//     void erase(string &word) {
//         eraseUtil(root, word);
//     }

//     bool allChildrenNull(TrieNode* node) {
//         for (int i = 0; i < 26; i++) {
//             if (node->children[i] != NULL) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };
