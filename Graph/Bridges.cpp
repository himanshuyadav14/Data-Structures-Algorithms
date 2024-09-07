// #include <vector>
// using namespace std;

// void dfs(int u, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<vector<int>>& adj, vector<vector<int>>& bridges, int& time) {
//     disc[u] = low[u] = ++time;
//     for (int v : adj[u]) {
//         if (disc[v] == -1) {  // v is not visited
//             parent[v] = u;
//             dfs(v, disc, low, parent, adj, bridges, time);

//             low[u] = min(low[u], low[v]);

//             // If the lowest vertex reachable from subtree under v is below u in DFS tree, then u-v is a bridge
//             if (low[v] > disc[u]) {
//                 bridges.push_back({u, v});
//             }
//         } else if (v != parent[u]) {  // Back edge
//             low[u] = min(low[u], disc[v]);
//         }
//     }
// }

// vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
//     vector<vector<int>> adj(v);
//     for (const auto& edge : edges) {
//         adj[edge[0]].push_back(edge[1]);
//         adj[edge[1]].push_back(edge[0]);
//     }

//     vector<int> disc(v, -1);  // Discovery times of visited vertices
//     vector<int> low(v, -1);   // Lowest points of visited vertices
//     vector<int> parent(v, -1); // Parent vertices in DFS tree
//     vector<vector<int>> bridges; // To store bridges
//     int time = 0;

//     for (int i = 0; i < v; i++) {
//         if (disc[i] == -1) {
//             dfs(i, disc, low, parent, adj, bridges, time);
//         }
//     }

//     return bridges;
// }
