//Using BFS //Kahn's Algo
//------------------------------------------*****************************----------------------------------------------
// vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
//     unordered_map<int,vector<int>>adj;
//     for(int i=0; i<e; i++){
//         int u = edges[i][0];
//         int w = edges[i][1];

//         adj[u].push_back(w);
//     }

//     //find all indegree
//     vector<int>inDegree(v);
//     for(auto i:adj){
//         for(auto j:i.second) inDegree[j]++;
//     }

//     //Push 0 indegree node
//     queue<int>q;
//     for(int i=0; i<v; i++){
//         if(inDegree[i] == 0) q.push(i);
//     }

//     //Do BFS
//     vector<int>ans;
//     while(!q.empty()){
//         int front = q.front();
//         q.pop();

//         ans.push_back(front);

//         for(auto neighbour:adj[front]){
//             inDegree[neighbour]--;
//             if(inDegree[neighbour] == 0) q.push(neighbour);
//         }
//     }


//     return ans;
// }
//------------------------------------------*****************************----------------------------------------------

//Using DFS

//------------------------------------------*****************************----------------------------------------------
// void tsDFS(int node, unordered_map<int,vector<int>>& adj, unordered_map<int,bool>& visited, 
// stack<int>&st){
//     visited[node] = true;

//     for(auto &neighbour:adj[node]){
//         if(!visited[neighbour]){
//             tsDFS(neighbour, adj, visited, st);
//         }
//     }

//     st.push(node);
// }

//------------------------------------------*****************************----------------------------------------------
// vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
//     unordered_map<int,vector<int>>adj;
//     for(int i=0; i<e; i++){
//         int u = edges[i][0];
//         int w = edges[i][1];

//         adj[u].push_back(w);
//     }

//     unordered_map<int,bool>visited;
//     stack<int>st;
//     for(int i=0; i<v; i++){
//         if(!visited[i]){
//             tsDFS(i, adj, visited, st);
//         }
//     }

//     vector<int>ans;
//     while(!st.empty()){
//         ans.push_back(st.top());
//         st.pop();
//     }

//     return ans;
// }