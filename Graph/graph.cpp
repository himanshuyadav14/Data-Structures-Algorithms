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
        g.addEdge(u, v, 0);
    }
    //print the graph
    g.printAdjList();
    return 0;
}