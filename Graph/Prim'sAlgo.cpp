//Babbar

// #include <bits/stdc++.h> 
// vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
// {
//     unordered_map<int,vector<pair<int,int>>>adj;
//     for(int i=0; i<m; i++){
//         int u = g[i].first.first;
//         int v = g[i].first.second;
//         int wt = g[i].second;

//         adj[u].push_back({v,wt});
//         adj[v].push_back({u,wt});
//     }

//     vector<int>key(n+1,INT_MAX);
//     vector<bool>mst(n+1, false);
//     vector<int>parent(n+1, -1);

//     key[1] = 0;
//     parent[1] = -1;

//     for(int i=1; i<=n; i++){
//         int mini = INT_MAX;
//         int u;

//         for(int v=1; v<=n; v++){
//             if(mst[v] == false && key[v] < mini){
//                 u = v;
//                 mini = key[v];
//             }
//         }

//         mst[u] = true;

//         for(auto &neighbour: adj[u]){
//             int v = neighbour.first;
//             int wt = neighbour.second;

//             if(mst[v]==false && wt < key[v]){
//                 key[v] = wt;
//                 parent[v] = u;
//             }
//         }
//     }

//     vector<pair<pair<int, int>, int>>result;
//     for(int i=2; i<=n; i++){
//         result.push_back({{parent[i],i},key[i]});
//     }

//     return result;
// }


