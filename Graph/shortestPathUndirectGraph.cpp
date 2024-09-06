// //unweighted and undirected graph

// vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
// 	//create adjacency List
// 	unordered_map<int,vector<int>>adj;

// 	for(int i=0; i<edges.size(); i++){
// 		int u = edges[i].first;
// 		int v = edges[i].second;

// 		adj[u].push_back(v);
// 		adj[v].push_back(u);
// 	}

// 	//do BFS
// 	unordered_map<int,bool> visited;
// 	unordered_map<int,int>parent;
// 	queue<int>q;
// 	q.push(s);
// 	parent[s] = -1;
// 	visited[s] = true;

// 	while(!q.empty()){
// 		int front = q.front();
// 		q.pop();

// 		for(auto &neighbour : adj[front]){
// 			if(!visited[neighbour]){
// 				visited[neighbour] = true;
// 				parent[neighbour] = front;
// 				q.push(neighbour); 
// 			}
// 		}
// 	}

// 	//Prepare shortest path
// 	vector<int>ans;
// 	int currNode = t;
// 	ans.push_back(currNode);

//Making ans by doing backtracking on parents
// 	while(currNode != s){
// 		currNode = parent[currNode];
// 		ans.push_back(currNode);
// 	}
	
// 	reverse(ans.begin(),ans.end());
// 	return ans;
// }
