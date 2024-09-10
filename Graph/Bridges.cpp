// class Solution {
// private:
//     void DFS(int node, int parent, vector<vector<int>>& adj, vector<int>& disc,
//     vector<int>& low, vector<bool>& visited, vector<vector<int>>& Bridges, int count){
//         disc[node] = low[node] = timer++;
//         visited[node] = true;

//         for(auto &nbr: adj[node]){
//             if(nbr == parent) continue;
//             else if(visited[nbr]){
//                 low[node] = min(low[node], low[nbr]);
//             }else{
//                 DFS(nbr, node, adj, disc, low, visited, Bridges, timer);
//                 low[node] = min(low[node], low[nbr]);

//                 //Bridge exist or not
//                 if(low[nbr] > disc[node]){
//                     Bridges.push_back({nbr,node});
//                 }
//             }
//         }

//     }
// public:
//     vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
//         //creation of adjacency list;
//         vector<vector<int>>adj(n);
//         for(int i=0; i<connections.size(); i++){
//             int u = connections[i][0];
//             int v = connections[i][1];

//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         vector<vector<int>>Bridges;
//         vector<int>disc(n,0);
//         vector<int>low(n,0);
//         vector<bool>visited(n,false);

//         int timer = 0;

//         DFS(0, -1, adj, disc, low, visited, Bridges, timer);

//         return Bridges;
//     }
// };