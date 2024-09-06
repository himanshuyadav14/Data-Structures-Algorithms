#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <limits.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, vector<pair<int, int> > > adjList;

    void addEdge(int u, int v, int wt)
    {
        adjList[u].push_back(make_pair(v, wt));
    }

    void printAdjList()
    {
        // Iterate over each element in the adjacency list
        for (unordered_map<int, vector<pair<int, int> > >::iterator it = adjList.begin(); it != adjList.end(); ++it)
        {
            cout << it->first << "->";
            for (vector<pair<int, int> >::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
            {
                cout << "(" << jt->first << ", " << jt->second << "), ";
            }
            cout << endl;
        }
    }

    //Topological sort DFS
    void DFS(int node, unordered_map<int, bool> &visited, stack<int> &st)
    {
        visited[node] = true;

        for (auto &neighbour : adjList[node])
        {
            if (!visited[neighbour.first])
            {
                DFS(neighbour.first, visited, st);
            }
        }

        st.push(node);
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &st)
    {
        dist[src] = 0;

        while (!st.empty())
        {
            int top = st.top();
            st.pop();

            if(dist[top] != INT_MAX){
                for(auto& i : adjList[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdjList();

    int n = 6;
    //Topological Sort
    unordered_map<int, bool> visited;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.DFS(i, visited, st);
        }
    }

    int src = 1;
    vector<int> dist(n);
    fill(dist.begin(), dist.end(), INT_MAX);
    g.getShortestPath(src, dist, st);

    for(int i=0; i<n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;

    return 0;
}
