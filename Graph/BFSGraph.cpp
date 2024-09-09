// void bfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int>& ans, int node) {
//     queue<int> q;
//     q.push(node);
//     visited[node] = true;

//     while (!q.empty()) {
//         int frontNode = q.front();
//         q.pop();

//         ans.push_back(frontNode);

//         // Traverse all neighbours
//         for (auto& i : adj[frontNode]) {
//             if (!visited[i]) {
//                 q.push(i);
//                 visited[i] = true;
//             }
//         }
//     }
// }

// vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
//     vector<int> ans;
//     vector<bool> visited(n, false);  


//     bfs(adj, visited, ans, 0);


//     return ans;
// }