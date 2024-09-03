// class TrieNode{
//     public:
//     char data;
//     bool isTerminal;
//     TrieNode * children[26];

//     TrieNode(char d){
//         this->data = d;
//         isTerminal = false;
//         for(int i = 0; i<26; i++){
//             children[i] = NULL;
//         }
//     }
// };

// class Trie{
//     public:
//     TrieNode* root;
    
//     Trie(){
//         root = new TrieNode('\0');
//     }

//     void insertHelper(TrieNode* root, string word){
//         //base case
//         if(word.length()==0){
//             root->isTerminal = true;
//             return;
//         }

//         //current character fetch
//         char ch = word[0];
//         //mapping character to an index integer
//         int index = ch-'a';

//         //child node create
//         TrieNode*child;

//         //2 cases exist
        
//         //The alphabet is already present
//         if(root->children[index] != NULL){
//             child = root->children[index];
//         }else{
//             //alphabet is absent
//             child = new TrieNode(ch);
//             root->children[index] = child;
//         }

//         //recursion will take care of rest cases
//         insertHelper(child,word.substr(1));
//     }

//     void insert(string word){
//         insertHelper(root,word);
//         // cout<<word<<" Insert Successfully"<<endl;
//     }

//     void getNames(TrieNode* curr, string prefix, vector<string>& temp){
//     //base case
//     if(curr->isTerminal){
//         temp.push_back(prefix);
//     }

//     for(char ch = 'a'; ch <= 'z'; ch++){
//         TrieNode * next = curr->children[ch-'a'];

//         //found
//         if(next!=NULL){
//             prefix.push_back(ch);
//             //Recursion
//             getNames(next,prefix,temp);
//             prefix.pop_back();
//         }
//     }
// }

//     vector<vector<string> > getAns(string word){
//     TrieNode * prev = root;
//     vector<vector<string> > ans;
//     string prefix = "";

//     for(int i =0; i<word.length(); i++){
//         char lastch = word[i];
//         prefix.push_back(lastch);

//         TrieNode * curr = prev->children[lastch - 'a'];

//         if(curr==NULL){
//             break;
//         }else{
//             vector<string> tempAns;
//             getNames(curr,prefix,tempAns);
//             ans.push_back(tempAns);
//             prev = curr;
//         }
//     }
//     return ans;
// }

// };


// vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
// {
//     //    Write your code here.
//     Trie*t = new Trie();
    
//     for(int i = 0; i<contactList.size(); i++){
//         string str = contactList[i];
//         t->insert(str);
//     }

//     return t->getAns(queryStr);
// }