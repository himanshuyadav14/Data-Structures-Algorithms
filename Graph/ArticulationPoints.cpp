// class Solution {
// private:
//     void DFS(int node, int parent, vector<int> adj[], vector<int>& disc, 
//     vector<int>& low, vector<bool>& visited, vector<bool>& articulation, int& count) {
//         disc[node] = low[node] = count++;
//         visited[node] = true;
//         int children = 0; // Count of children in DFS tree
        
//         for (auto &nbr : adj[node]) {
//             if (nbr == parent) continue; // Skip the parent of the current node

//             if (visited[nbr]) {
//                 // Back edge, update the low-link value
//                 low[node] = min(low[node], disc[nbr]);
//             } else {
//                 // Recurse deeper into DFS
//                 DFS(nbr, node, adj, disc, low, visited, articulation, count);

//                 // Update the low-link value after returning from DFS
//                 low[node] = min(low[node], low[nbr]);

//                 // Check for articulation point
//                 if (parent != -1 && low[nbr] >= disc[node]) {
//                     articulation[node] = true;
//                 }
//                 children++;
//             }
//         }

//         // Special case: if the node is the root and has more than one child, it's an articulation point
//         if (parent == -1 && children > 1) {
//             articulation[node] = true;
//         }
//     }

// public:
//     vector<int> articulationPoints(int n, vector<int> adj[]) {
//         int count = 0; // Discovery count
//         vector<int> disc(n, -1);  // Discovery times of visited vertices
//         vector<int> low(n, -1);   // Lowest points of visited vertices
//         vector<bool> visited(n, false); // To keep track of visited vertices
//         vector<bool> articulation(n, false); // To store articulation points (true/false)

//         // Perform DFS from node 0 assuming the graph is connected
//         DFS(0, -1, adj, disc, low, visited, articulation, count);

//         // Extract the articulation points
//         vector<int> articulationPoints;
//         for (int i = 0; i < n; i++) {
//             if (articulation[i]) {
//                 articulationPoints.push_back(i);
//             }
//         }

//         // If no articulation points were found, return {-1}
//         if (articulationPoints.empty()) {
//             return {-1};
//         }

//         return articulationPoints;
//     }
// };