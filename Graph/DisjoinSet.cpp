#include<iostream>
using namespace std;

class DisjoinSet{
    vector<int>rank, parent;
    public:
    DisjoinSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int parentOfU = findParent(u);
        int parentOfV = findParent(v);

        if(parentOfU == parentOfV) return;
        if(rank[parentOfU] < rank[parentOfV]){
            parent[parentOfU] = parentOfV;
        }else if(rank[parentOfV] < rank[parentOfU]){
            parent[parentOfV] = parentOfU;
        }else{
            parent[parentOfV] = parentOfU;
            rank[parentOfU]++;
        }
    }
};

int main(){

}