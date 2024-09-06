//BFS

//Using Kahn's Algo (Topological Sort)
// int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
//   unordered_map<int,vector<int>>adj;
//     for(int i=0; i<edges.size(); i++){
//         int u = edges[i].first - 1;
//         int v = edges[i].second - 1;

//         adj[u].push_back(v);
//     }

//     //find all indegree
//     vector<int>inDegree(n);
//     for(auto i:adj){
//         for(auto j:i.second) inDegree[j]++;
//     }

//     //Push 0 indegree node
//     queue<int>q;
//     for(int i=0; i<n; i++){
//         if(inDegree[i] == 0) q.push(i);
//     }

//     //Do BFS
//     int cnt = 0;
//     while(!q.empty()){
//         int front = q.front();
//         q.pop();

//         cnt++;

//         for(auto neighbour:adj[front]){
//             inDegree[neighbour]--;
//             if(inDegree[neighbour] == 0) q.push(neighbour);
//         }
//     }

//     return cnt != n;
// }

//DFS

// bool checkCycleDFS(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited, unordered_map<int, vector<int>>& adj) {
//     visited[node] = true;
//     dfsVisited[node] = true;

//     for (auto& neighbour : adj[node]) {
//         if (!visited[neighbour]) {
//             bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
//             if (cycleDetected) return true;
//         } else if (dfsVisited[neighbour]) {
//             return true;
//         }
//     }

//     dfsVisited[node] = false;  // Remove from recursion stack after processing
//     return false;
// }

// int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
//     unordered_map<int, vector<int>> adj;
//     int m = edges.size();
//     for (int i = 0; i < m; i++) {
//         int u = edges[i].first;
//         int v = edges[i].second;

//         adj[u].push_back(v);  // Directed graph, so only one direction
//     }

//     unordered_map<int, bool> visited;
//     unordered_map<int, bool> dfsVisited;

//     for (int i = 1; i <= n; i++) {
//         if (!visited[i]) {
//             bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
//             if (cycleFound) return 1;  // Return 1 if a cycle is detected
//         }
//     }

//     return 0;  // No cycle found
// }
