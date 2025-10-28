#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class Graph
{
public:
    unordered_map<int, vector<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        // create an edge from u to v
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto &i : adj)
        {
            // {node, list of nodes} or {node, vector<int>}
            // i.first is the node
            // i.second is the vector of nodes which are connected to the node i.first
            cout << i.first << "->";
            for (auto &j : i.second)
                cout << j << ", ";
            cout << endl;
        }
    }
};

int main()
{

    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;
    //creation of graph
    Graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        
        // Validate that nodes are in range [0, n-1]
        if (u < 1 || v < 1 || u > n || v > n)
        {
            cout << "Invalid edge: Node out of range!" << endl;
            cout << "Expected nodes in range [0, " << n-1 << "]" << endl;
            continue;
        }
        
        g.addEdge(u, v, 0);
    }
    //print the graph
    g.printAdjList();
    return 0;
}


// Coding ninjas solution of creating and printing graph
// vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // n nodes
    // m edges

//     vector<vector<int>>ans(n);

//     for(int i=0; i<m; i++){
//         int u = edges[i][0];
//         int v = edges[i][1];

//         ans[u].push_back(v);
//         ans[v].push_back(u);
//     }


//     vector<vector<int>>ans2;
    
//     for(int i=0; i<n; i++){
//         vector<int>temp;
//         temp.push_back(i);

//         for(auto j:ans[i]) temp.push_back(j);
//         ans2.push_back(temp);
//     }

//     return ans2;
// }

