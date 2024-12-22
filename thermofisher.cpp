#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Linkedlist
// Q.1 Detect and remove cycle in linkedlist?
// Assuming ListNode* is a linkedlist implementation
ListNode *cycleDetect(ListNode *head)
{
    if (!head || !head->next)
        return NULL;

    ListNode *slow = head;
    ListNode *fast = head;

    // Step 1: Detect Cycle using Floyd's algorithm
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break; // cycle detected
    }

    if (slow != fast)
        return head;

    // Step 2: Find the start of the cycle
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Step 3: Remove the cycle
    ListNode *cycleStart = slow;
    ListNode *temp = cycleStart;

    while (temp->next != cycleStart)
    {
        temp = temp->next;
    }
    temp->next = NULL;

    return head;
}

// T.C = O(n);
// S.C = O(1);

// Q.2 Reverse Nodes in K group?
// Assuming ListNode* is a linkedlist implementation
int getLength(ListNode *curr)
{
    int length = 0;
    while (curr)
    {
        curr = curr->next;
        length++;
    }
    return length;
}

ListNode *reverKgroup(ListNode *head, int k)
{
    // Base case
    if (!head || k <= 1)
        return head;

    // Check if there are at least k nodes to reverse
    int length = getLength(head);
    if (length < k)
        return head;

    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;
    int count = 0;

    while (curr && count < k)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
        count++;
    }

    head->next = reverseKgroup(curr, k);

    return prev;
}
// T.C = O(n);
// S.C = O(n/k); recursion stack

// Binary Tree
//  Assuming TreeNode* is a Tree's Node implementation
//  Q.3 Lowest common ancestor of binary tree
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // base case
    if (!root)
        return NULL;
    if (root == p || root == q)
        return root;

    TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

    if (!leftAns && rightAns)
        return rightAns;
    else if (leftAns && !rightAns)
        return leftAns;
    else if (!leftAns && !rightAns)
        return NULL;
    else
        return root;
}
// T.C = O(n)
// S.C = O(n)for worst and O(logn) average

// Q.4 Serialize and deserialize Binary
// Assuming TreeNode* is a Tree's Node implementation
void preorder(TreeNode *root, string &encoded)
{
    // base case
    if (!root)
    {
        encoded += "#,";
        return;
    }

    encoded += to_string(root->val) + ",";
    preorder(root->left, encoded);
    preorder(root->right, encoded);
}
string serialize(TreeNode *root)
{
    string encoded = "";
    preorder(root, encoded);
    return encoded;
}

TreeNode *solve(string data, int idx)
{
    // base case
    if (idx >= data.size())
        return NULL;

    int start = idx;
    while (idx < data.size() && data[idx] != ",")
        idx++;

    string value = data.substr(start, idx - start);
    idx++;

    if (value == "#")
        return NULL;

    TreeNode *root = new TreeNode(stoi(value));
    root->left = solve(data, idx);
    root->right = solve(data, idx);

    return root;
}

TreeNode *deserialize(string data)
{
    int idx = 0;
    return solve(data, idx);
}

// T.C = O(n)
// S.C = O(n)

// Binary Search Tree
// Q.5 find Kth smallest element in a binary search tree
void solve(TreeNode *root, int &k, int &ans)
{
    if (!root)
        return;

    solve(root->left, k, ans);

    if (--k == 0)
    {
        ans = root->val;
        return;
    }

    solve(root->right, k, ans);
}

int kthSmallest(TreeNode *root, int k)
{
    int ans = 0;
    solve(root, k, ans);
    return ans;
}

// Time Complexity:
// Best case: O(k)
// Worst case: O(n)
// Space Complexity:
// Best case: O(log n)
// Worst case: O(n)

// Heaps
// Q.6 Find kth largest element in an array
int findKthLargest(vector<int> nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
        if (pq.size() > k)
            pq.pop();
    }

    return pq.top();
}
// T.C = O(nlogK)
// S.C = O(K)

// Q.7 Merge K sorted arrays
vector<int> mergeKSortedArrays(vector<vector<int>> &arrays)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> output;

    for (int i = 0; i < arrays.size(); i++)
        pq.push({arrays[i][0], {i, 0}});

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int mini = top.first;
        int arrayIndex = top.second.first;
        int idx = top.second.second;

        outpush.push_back(mini);

        if (idx + 1 < arrays[arrayIndex].size())
        {
            pq.push({arrays[arrayIndex][idx + 1], {arrayIndex, idx + 1}});
        }
    }

    return output;
}

// T.C = O(nlogk)
// S.C = O(nlogk)

// Stack
// Q.8 Evaluate reverse polish notation
int solve(int a, int b, string operand)
{
    if (operand == "+")
        return b + a;
    if (operand == "-")
        return b - a;
    if (operand == "*")
        return b * a;
    if (operand == "/")
        return b / a;
    return 0;
}
int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    int n = tokens.size();

    for (int i = 0; i < n; i++)
    {
        string ch = tokens[i];
        if (ch == "+" || ch == "-" || ch == "*" || ch == "/")
        {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            int ans = solve(a, b, ch);

            st.push(ans);
        }
        else
            st.push(stoi(ch));
    }

    return st.top();
}

// T.C = O(n)
// S.C = O(n)

// Q:9 Next Greater Element
vector<int> NextGreater(vector<int> nums)
{
    int n = nums.size();
    vector<int> result(n);
    stack<int> st;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int current = nums[i];

        while (!st.empty() && st.top() <= current)
        {
            st.pop();
        }

        result[i] = st.empty() ? -1 : st.top();

        st.push(current);
    }

    return result;
}

// T.C = O(n)
// S.C = O(n)

// Queues
//  Q:10 sliding window maximum

// T.C = O(n*k)
// vector<int>slidingWindowMaximum(vector<int>nums, int k){
//     vector<int>ans;

//     for(int i=0; i<=nums.size()-k; i++){
//         int maxElement = INT_MIN;
//         for(int j=i; j<i+k; j++){
//             maxElement = max(maxElement, nums[j]);
//         }
//         ans.push_back(maxElement);
//     }

//     return ans;
// }

// T.C = O(nlogk)
// S.C = O(k)
// vector<int>slidingWindowMaximum(vector<int>nums, int k){
//     vector<int>ans;
//     priority_queue<pair<int,int>>pq;

//     for(int i=0; i<nums.size(); i++){
//         pq.push({nums[i],i})

//         if(i >= k-1){
//             while( !pq.empty() && pq.top().second <= i-k){
//                 pq.pop();
//             }
//             ans.push_back(pq.top().first);
//         }
//     }

//     return ans;
// }

// T.C = O(n)
// S.C = O(k)
vector<int> slidingWindowMaximum(vector<int> nums, int k)
{
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
        {
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

// Q11. Design circular queue
class CircularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int k)
    {
        size = k;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue(int val)
    {
        if (isFull())
            return false;
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % size;

        arr[rear] = val;
        return true;
    }

    bool dequeue()
    {
        if (isEmpty())
            return false;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
        return true;
    }

    int front()
    {
        if (isEmpty())
            return -1;
        else
            return arr[front];
    }

    int rear()
    {
        if (isEmpty())
            return -1;
        else
            return arr[rear];
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return front == (rear + 1) % size;
    }
};

// Recursion
// Q12: Subset sum problem?
bool solve(vector<int> nums, int idx, int target, int currentSum)
{
    // Base case
    if (idx >= nums.size())
        return false;
    if (currentSum == target)
        return true;

    bool include = solve(nums, idx + 1, target, currentSum + nums[idx]);
    bool exclude = solve(nums, idx + 1, target, currentSum);

    return include | exclude;
}
bool subsetSum(vector<int> nums, int target)
{
    return solve(nums, 0, target, 0);
}
// T.C = O(2^N)
// S.C = O(N)

// Q13: Generate All permutation in a string
unordered_set<char> set;
void solve(string &str, string &temp, vector<string> &result)
{
    // Base case
    if (temp.size() == str.size())
    {
        result.push_back(temp);
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (set.find(str[i]) == set.end())
        {
            temp.push_back(ch);
            set.insert(ch);

            solve(str, temp, result);

            temp.pop_back();
            set.erase(ch);
        }
    }
}
vector<string> generateAllPermutation(string str)
{
    vector<string> result;
    string temp = "";
    solve(str, temp, result);
    return result;
}

// T.C = O(N!)
// S.C = O(N)

// Backtracking
// Q14. N Queens
bool isSafe(vector<string> &board, int row, int col)
{
    int x = row, y = col;

    // checking in left direction
    while (y >= 0)
    {
        if (board[x][y] == 'Q')
            return false;
        y--;
    }

    // check in upper diagonal direction
    x = row, y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 'Q')
            return false;
        x--;
        y--;
    }

    // check in upper left diagonal
    x = row, y = col;
    while (x < board.size() && y >= 0)
    {
        if (board[x][y] == 'Q')
            return false;
        x++;
        y--;
    }

    return true;
}
void solve(vector<string> &board, vector<vector<string>> &ans, int n, int col)
{
    // Base case
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';
            solve(board, ans, n, col + 1);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    solve(board, ans, n, 0);
    return ans;
}

// T.C = O(N!*N)
// S.C = O(N^2)

// Q15. Word Search in a grid
bool solve(vector<vector<char>> &grid, int x, int y, string &word, int idx)
{
    if (idx >= word.length())
        return true;

    char temp = grid[x][y];
    grid[x][y] = '#';

    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    for (auto &dir : directions)
    {
        int newX = x + dir[0];
        int newY = y + dir[1];

        if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == word[idx])
        {
            if (solve(grid, newX, newY, word, idx + 1))
                return true;
        }
    }

    grid[x][y] = temp;
    return false;
}
bool exist(vector<vector<char>> grid, string word)
{
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == word[0] && solve(grid, i, j, word, 1))
            {
                return true;
            }
        }
    }

    return false;
}

// T.C = O(N*M*4^L)
// S.C = O(L)//Recusrion stack

// Dynamic Programming
// Q.16 Longest Common Subsequence
int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    // Base case
    if (i == s.length() || j == t.length())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
        return dp[i][j] = 1 + solve(s, t, i + 1, j + 1, dp);
    else
        return dp[i][j] = max(solve(s, t, i + 1, j, dp), solve(s, t, i, j + 1, dp));
}
int longestCommonSubsequence(string s, string t)
{
    int m = s.length();
    int n = t.length();
    // vector<vector<int>>dp(m+1,vector<int>(n+1,0));

    vector<int> curr(t.length() + 1, 0);
    vector<int> next(t.length() + 1, 0);

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (s[i] == t[j])
                curr[j] = 1 + next[j + 1];
            else
                curr[j] = max(next[j], curr[j + 1]);
        }
        next = curr;
    }

    return curr[0];
}

// T.C = O(m*n)
// S.C = O(n)

// Q.17 Unique Paths 2
int solve(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<int>> &dp)
{
    // Base cases
    if (i < 0 || i >= m || j < 0 || j >= n)
        return 0;
    if (grid[i][j] == 1)
        return 0; // Obstacle
    if (i == m - 1 && j == n - 1)
        return 1; // Reached destination

    // Check if already computed
    if (dp[i][j] != -1)
        return dp[i][j];

    // Recursive calls
    dp[i][j] = solve(grid, i, j + 1, m, n, dp) + solve(grid, i + 1, j, m, n, dp);
    return dp[i][j];
}

int uniquePathsWithObstacles(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize memoization table
    return solve(grid, 0, 0, m, n, dp);
}
// T.C = O(m*n)
// S.C = O(m*n)

// 2 pointers
// Q18. 3Sum? (i!=j && j!=k && k!=i) && nums[i] + nums[j] + nums[k] = 0;
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end()); // O(nlogn)
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    { // O(n)
        while (i > 0 && nums[i - 1] == nums[i])
            i++;
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        { // O(n)
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && nums[j - 1] == nums[j])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }

    return ans;
}

// T.C = O(n^2) + O(nlogn)
// S.C = O(K)

// Q19. Minimum Window To Sort?
int MinimumWindowSort(vector<int> &nums)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left < n - 1 && nums[left] <= nums[left + 1])
        left++;
    if (left == n - 1)
        return 0;
    while (right > 0 && nums[right] >= nums[right - 1])
        right--;

    int minEle = INT_MAX;
    int maxEle = INT_MIN;
    for (int i = left; i <= right; i++)
    {
        minEle = min(minEle, nums[i]);
        maxEle = max(maxEle, nums[i]);
    }

    while (left > 0 && nums[left - 1] > minEle)
        left--;
    while (right < n - 1 && nums[right + 1] < maxEle)
        right++;

    return right - left + 1;
}
// T.C = O(n)
// S.C = O(1)

// Sliding Window
// Q20. Maximum Sum of distinct subarray of size k
long long maximumSubarraySum(vector<int> &nums, int k)
{
    long long result = INT_MAX;
    unordered_map<int, int> freq;
    long long sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
        freq[nums[i]]++;
    }

    if (freq.size() == k)
        result = max(result, sum);

    for (int i = k; i < nums.size(); i++)
    {
        sum += nums[i];
        freq[nums[i]]++;

        sum -= nums[i - k];
        freq[nums[i - k]]--;

        if (freq[nums[i - k]] == 0)
            freq.erase(nums[i - k]);

        if (freq.size() == k)
        {
            result = max(result, sum);
        }
    }

    return result == INT_MAX ? 0 : result;
}

// T.C = O(n)
// S.C = O(K)

// Q21. Longest SubString with atmost k distinct characters
int largestSubstringKdistinct(string &s, int k)
{
    unordered_map<char, int> freq;
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < s.length(); right++)
    {
        freq[s[right]]++;

        while (freq.size() > k)
        {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

// T.C = O(N)
// S.C = O(K)

// Binary Search
// Q22. Find first and last position of an element in an sorted array
int firstPos(vector<int> &nums, int target, int n)
{
    int left = 0;
    int right = n - 1;
    int ans = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            right = mid - 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}
int lastPos(vector<int> &nums, int target, int n)
{
    int left = 0;
    int right = n - 1;
    int ans = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}
vector<int> firstAndLast(vector<int> nums, int target)
{
    int n = nums.size();
    int first = firstPos(nums, target, n);
    int last = lastPos(nums, target, n);
    return {first, last};
}
// T.C = O(logn)
// S.C = O(1)

// Tries
// Q23. Implement Trie (prefix tree)
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
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (node->children.find(ch) == node->children.end())
            {
                node->children[ch] = new TrieNode(ch);
            }
            node = node->children[ch];
        }
        node->isTerminal = true;
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (node->children.find(ch) == node->children.end())
            {
                return false;
            }
            node = node->children[ch];
        }
        return node->isTerminal;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            if (node->children.find(ch) == node->children.end())
            {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }
};

// T.C = O(L)
// S.C = O(N*L)

// Graphs
// Q.24. BFS in graph?
void solve(vector<vector<int>> &adj, int node, vector<int> &ans, vector<bool> &vis)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto &nbr : adj[node])
        {
            if (!vis[nbr])
            {
                q.push(nbr);
                vis[nbr] = true;
            }
        }
    }
}
vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    vector<int> ans;
    vector<bool> vis(n, false);

    solve(adj, 0, ans, vis);
    return ans;
}
// T.C = O(V+E)
// S.C = O(V+E)

// Q.25. DFS in graph?
void dfs(int node, vector<bool> &visited, unordered_map<int, vector<int>> &adj,
         vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    for (auto &i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }

    return ans;
}

// T.C = O(V+E)
// S.C = O(V+E)

// Q.26. cycle detection in undirected graph using BFS?
bool isCyclicBFS(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, int src)
{
    unordered_map<int, int> parent;
    queue<int> q;

    q.push(src);
    parent[src] = -1;
    visited[src] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto &neighbour : adj[frontNode])
        {
            if (visited[neighbour] && neighbour != parent[frontNode])
                return true;
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}
// T.C = O(V+E)
// S.C = O(V+E)

// Q.27. cycle detection in undirected graph using DFS?
bool isCyclicDFS(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, int node, int parent)
{
    visited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = isCyclicDFS(adj, visited, neighbour, node);
            if (cycleDetected)
                return true;
        }
        else if (neighbour != parent)
        {
            return true;
        }
    }
    return false;
}
// T.C = O(V+E)
// S.C = O(V+E)

// Q.28 cycle detection in directed graph using DFS?
bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, vector<int>> &adj)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto &neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
            if (cycleDetected)
                return true;
        }
        else if (dfsVisited[neighbour])
        {
            return true;
        }
    }

    dfsVisited[node] = false; // Remove from recursion stack after processing
    return false;
}

// Q.29 Topological Sort? (DFS) DAG->
void tsDFS(int node, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited,
           stack<int> &st)
{
    visited[node] = true;

    for (auto &neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            tsDFS(neighbour, adj, visited, st);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int w = edges[i][1];

        adj[u].push_back(w);
    }

    unordered_map<int, bool> visited;
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            tsDFS(i, adj, visited, st);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

// Q.30 Topological Sort (BFS) Kahn's Algo
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int w = edges[i][1];

        adj[u].push_back(w);
    }

    // Find indegree
    vector<int> inDegree(v, 0);
    for (auto i : adj)
    {
        for (auto j : i.second)
            inDegree[j]++;
    }

    // Push 0 indegree nodes into q
    queue<int> q;
    for (int i = 0; i < v; i++)
        if (inDegree[i] == 0)
            q.push(i);

    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for (auto nbr : adj[front])
        {
            inDegree[nbr]--;
            if (inDegree[nbr] == 0)
                q.push(nbr);
        }
    }

    return ans;
}

// Q.31 cycle detection in directed graph using BFS?
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u].push_back(v);
    }

    // find all indegree
    vector<int> inDegree(n);
    for (auto i : adj)
    {
        for (auto j : i.second)
            inDegree[j]++;
    }

    // Push 0 indegree node
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    // Do BFS
    int cnt = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        cnt++;

        for (auto neighbour : adj[front])
        {
            inDegree[neighbour]--;
            if (inDegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    return cnt != n;
}

// Q32. Shortest Path in undirected graph?
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    // create adjacency List
    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // do BFS
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;

    q.push(s);
    parent[s] = -1;
    visited[s] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto &neighbour : adj[front])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }

    // Prepare shortest path
    vector<int> ans;
    int currNode = t;
    ans.push_back(currNode);

    // Making ans by doing backtracking on parents
    while (currNode != s)
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// Q33. Shortest path in Directed acyclic graph(DAG)?
void topologicalSort(int node, vector<bool>& visited, stack<int>& topoStack, unordered_map<int, vector<pair<int, int>>>& adj) {
    visited[node] = true;

    for (auto& neighbor : adj[node]) {
        int nbrNode = neighbor.first;
        if (!visited[nbrNode]) {
            topologicalSort(nbrNode, visited, topoStack, adj);
        }
    }

    topoStack.push(node);
}

vector<int> shortestPathDAG(int v, vector<vector<int>>& edges, int source) {
    // Step 1: Create adjacency list
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        adj[u].emplace_back(v, weight);
    }

    // Step 2: Perform topological sort
    vector<bool> visited(v, false);
    stack<int> topoStack;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topologicalSort(i, visited, topoStack, adj);
        }
    }

    // Step 3: Initialize distances
    vector<int> distance(v, INT_MAX);
    distance[source] = 0;

    // Step 4: Process nodes in topological order
    while (!topoStack.empty()) {
        int node = topoStack.top();
        topoStack.pop();

        if (distance[node] != INT_MAX) {
            for (auto& neighbor : adj[node]) {
                int nbrNode = neighbor.first;
                int edgeWeight = neighbor.second;

                if (distance[node] + edgeWeight < distance[nbrNode]) {
                    distance[nbrNode] = distance[node] + edgeWeight;
                }
            }
        }
    }

    return distance;
}

// Q34. Dijkstra Algo
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //create adjacency List;
    unordered_map<int,vector<pair<int,int>>>adj;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    //creation of distance array with infinite val;
    vector<int>dist(vertices, INT_MAX);

    //creation of set on basis of (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

    //Initialize distance and set with source node
    dist[source] = 0;
    pq.push({0,source});


    while(!pq.empty()){
        //Fetch top record
        auto top = pq.top();
        pq.pop();

        int nodeDistance = top.first;
        int topNode = top.second;

        for(auto neighbour: adj[topNode]){
            if(dist[topNode] + neighbour.second < dist[neighbour.first]){
                dist[neighbour.first] = dist[topNode] + neighbour.second;
                pq.push({dist[neighbour.first],neighbour.first});
            }
        }
    }

    return dist;
}

// Q35. Prim's Algo
// Q36. Bellman Ford
// Q37. Floyd Warshall Algo

// Disjoin Set
// Kruskals Algo
// Bridges in graph
// Articulation point in a graph
// Kosaraju Algo

// Searching Algos
// Quick Sort
// Merge Sort
// Selection Sort
// Insertion Sort

// OOPS implementation
// Abstraction
// Encapsulation
// Inhertance
// polymorphism

// SQL Queries
