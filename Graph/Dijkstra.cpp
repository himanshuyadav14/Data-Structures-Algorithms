// #include <bits/stdc++.h> 
// vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
//     //create adjacency List;
//     unordered_map<int,vector<pair<int,int>>>adj;
//     for(int i=0; i<edges; i++){
//         int u = vec[i][0];
//         int v = vec[i][1];
//         int wt = vec[i][2];

//         adj[u].push_back({v,wt});
//         adj[v].push_back({u,wt});
//     }

//     //creation of distance array with infinite val;
//     vector<int>dist(vertices);
//     fill(dist.begin(),dist.end(),INT_MAX);

//     //creation of set on basis of (distance, node)
//     set<pair<int,int>>set;

//     //Initialize distance and set with source node
//     dist[source] = 0;
//     set.insert({0,source});


//     while(!set.empty()){
//         //Fetch top record
//         auto top = *(set.begin());

//         int nodeDistance = top.first;
//         int topNode = top.second;

//         set.erase(set.begin());
//         for(auto neighbour: adj[topNode]){
//             if(dist[topNode] + neighbour.second < dist[neighbour.first]){
//                 auto record = set.find({dist[neighbour.first],neighbour.first});
//                 if(record != set.end()) set.erase(record);

//                 //dist update
//                 dist[neighbour.first] = dist[topNode] + neighbour.second;
//                 set.insert({dist[neighbour.first],neighbour.first});
//             }
//         }
//     }

//     return dist;
// }
