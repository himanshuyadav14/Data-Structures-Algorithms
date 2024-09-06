//BFS

// bool isCyclicBFS(unordered_map<int,vector<int>>& adj, unordered_map<int,bool>& visited, int src){
//     unordered_map<int,int>parent;
//     queue<int>q;

//     parent[src] = -1;
//     visited[src] = true;
//     q.push(src);

//     while(!q.empty()){
//         int frontNode = q.front();
//         q.pop();

//         for(auto& neighbour : adj[frontNode]){
//             if(visited[neighbour] && neighbour != parent[frontNode]) return true;
//             else if(!visited[neighbour]){
//                 q.push(neighbour);
//                 visited[neighbour] = true;
//                 parent[neighbour] = frontNode;
//             }
//         }   
//     }
//     return false;
// }
// string cycleDetection (vector<vector<int>>& edges, int n, int m)
// {
//     //create adjacency list
//     unordered_map<int,vector<int>>adj;
//     for(int i=0; i<m; i++){
//         int u = edges[i][0];
//         int v = edges[i][1];

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     unordered_map<int,bool> visited;
//     //To handle Disconnnected component
//     for(int i=0; i<n; i++){
//         if(!visited[i]){
//             bool ans = isCyclicBFS(adj,visited,i);
//             if(ans == 1) return "Yes";
//         }
//     }

//     return "No";

// }

//DFS

// bool isCyclicDFS(unordered_map<int,vector<int>>& adj, unordered_map<int,bool>& visited, int node, int parent){
//     visited[node] = true;
//     for(auto neighbour : adj[node]){
//         if(!visited[neighbour]){
//             bool cycleDetected = isCyclicDFS(adj, visited, neighbour, node);
//             if(cycleDetected) return true;
//         }else if(neighbour != parent){
//             return true;
//         }
//     }
//     return false;
// }
// string cycleDetection (vector<vector<int>>& edges, int n, int m)
// {
//     //create adjacency list
//     unordered_map<int,vector<int>>adj;
//     for(int i=0; i<m; i++){
//         int u = edges[i][0];
//         int v = edges[i][1];

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     unordered_map<int,bool> visited;
//     //To handle Disconnnected component
//     for(int i=0; i<n; i++){
//         if(!visited[i]){
//             bool ans = isCyclicDFS(adj,visited,i,-1);
//             if(ans == 1) return "Yes";
//         }
//     }

//     return "No";

// }

