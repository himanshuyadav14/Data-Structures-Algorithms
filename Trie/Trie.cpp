#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        // Base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Assumption : word will be in caps
        int index = word[0] - 'A';

        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        // Base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';

        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    bool removeUtil(TrieNode *root, string word)
    {
        // Base case: if the word is completely traversed
        if (word.length() == 0)
        {
            // Mark the current node as non-terminal
            if (root->isTerminal)
            {
                root->isTerminal = false;

                // If the current node has no children, it can be deleted
                for (int i = 0; i < 26; i++)
                {
                    if (root->children[i] != NULL)
                    {
                        return false; // Don't delete the node
                    }
                }
                return true; // Delete the node
            }
        }

        // Recursive case
        int index = word[0] - 'A';
        TrieNode *child = root->children[index];

        if (child == NULL)
        {
            return false; // Word not found
        }

        bool shouldDeleteChild = removeUtil(child, word.substr(1));

        // If the child should be deleted, remove the reference
        if (shouldDeleteChild)
        {
            delete child;
            root->children[index] = NULL;

            // Check if the current node is now redundant
            if (!root->isTerminal)
            {
                for (int i = 0; i < 26; i++)
                {
                    if (root->children[i] != NULL)
                    {
                        return false; // Don't delete the node
                    }
                }
                return true; // Delete the node
            }
        }

        return false;
    }

    void removeWord(string word)
    {
        removeUtil(root, word);
    }

    // LONGEST COMMON PREFIX UPDATED

    // void lcp(string str, string& ans){
    //     TrieNode* current = root;
    //     for(int i=0; i<str.length(); i++){
    //         char ch = str[i];

    //         if(current->childCount == 1){
    //             ans.push_back(ch);

    //             // Move forward in the trie
    //             int index = ch-'a';
    //             current = current->children[index];
    //         }else{
    //             break;
    //         }

    //         if(current->isTerminal) break;
    //     }
    // }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("ABCD");
    t->insertWord("AB");

    cout << "Present or not (J): " << t->searchWord("J") << endl;
    cout << "Present or not (ABCD): " << t->searchWord("ABCD") << endl;
    cout << "Present or not (AB): " << t->searchWord("AB") << endl;

    t->removeWord("ABCD");

    cout << "After removing ABCD" << endl;
    cout << "Present or not (ABCD): " << t->searchWord("ABCD") << endl;
    cout << "Present or not (AB): " << t->searchWord("AB") << endl;

    t->removeWord("AB");

    cout << "After removing AB" << endl;
    cout << "Present or not (AB): " << t->searchWord("AB") << endl;

    return 0;
}
