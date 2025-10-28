// void dfs(int node, vector<bool> &visited, stack<int> &st, unordered_map<int, vector<pair<int, int>>> &adj) {
//     visited[node] = true;

//     for (auto &[nbr, wt] : adj[node]) {
//         if (!visited[nbr]) {
//             dfs(nbr, visited, st, adj);
//         }
//     }

//     st.push(node); 
// }

// vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges) {
//     // Step 1: Build adjacency list
//     unordered_map<int, vector<pair<int, int>>> adj;
//     for (int i = 0; i < m; i++) {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         int w = edges[i][2];
//         adj[u].push_back({v, w});
//     }

//     // Step 2: Topological Sort (using DFS)
//     vector<bool> visited(n, false);
//     stack<int> st;
//     for (int i = 0; i < n; i++) {
//         if (!visited[i]) dfs(i, visited, st, adj);
//     }

//     // Step 3: Initialize distances
//     vector<int> dist(n, INT_MAX);
//     dist[0] = 0; // distance to source (0) is always 0

//     // Step 4: Relax edges in topological order
//     while (!st.empty()) {
//         int top = st.top();
//         st.pop();

//         if (dist[top] != INT_MAX) {
//             for (auto &[v, wt] : adj[top]) {
//                 if (dist[top] + wt < dist[v]) {
//                     dist[v] = dist[top] + wt;
//                 }
//             }
//         }
//     }

//     // Step 5: Replace unreachable vertices (INT_MAX) with -1
//     for (int i = 0; i < n; i++) {
//         if (dist[i] == INT_MAX) dist[i] = -1;
//     }

//     return dist;
// }