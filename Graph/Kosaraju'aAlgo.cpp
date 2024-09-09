// #include <unordered_map>
// #include <stack>
// #include <vector>
// using namespace std;

// void dfs(int node, unordered_map<int, bool>& visited, stack<int>& st, unordered_map<int, vector<int>>& adj) {
//     visited[node] = true;
//     for (auto nbr : adj[node]) {
//         if (!visited[nbr]) {
//             dfs(nbr, visited, st, adj);
//         }
//     }
//     st.push(node);  // Store node after its neighbors are processed
// }

// void revDfs(int node, unordered_map<int, bool>& visited, unordered_map<int, vector<int>>& transpose) {
//     visited[node] = true;
//     for (auto nbr : transpose[node]) {
//         if (!visited[nbr]) {
//             revDfs(nbr, visited, transpose);
//         }
//     }
// }

// int stronglyConnectedComponents(int v, vector<vector<int>>& edges) {
//     // Create adjacency list
//     unordered_map<int, vector<int>> adj;
//     for (int i = 0; i < edges.size(); i++) {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         adj[u].push_back(v);
//     }

//     // Topological sort using DFS
//     stack<int> st;
//     unordered_map<int, bool> visited;

//     for (int i = 0; i < v; i++) {
//         if (!visited[i]) {
//             dfs(i, visited, st, adj);
//         }
//     }

//     // Transpose of the graph
//     unordered_map<int, vector<int>> transpose;
//     for (int i = 0; i < v; i++) {
//         visited[i] = false;  // Reset visited map for the second DFS
//         for (auto nbr : adj[i]) {
//             transpose[nbr].push_back(i);
//         }
//     }

//     // Perform DFS in the order of the topological sort on the transposed graph
//     int count = 0;
//     while (!st.empty()) {
//         int top = st.top();
//         st.pop();
//         if (!visited[top]) {
//             count++;
//             revDfs(top, visited, transpose);
//         }
//     }

//     return count;
// }
