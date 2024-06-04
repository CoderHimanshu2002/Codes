#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //Create Adjaceny list...
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
       int u=g[i].first.first;
       int v=g[i].first.second;
       int w=g[i].second;

       adj[u].push_back({v,w});
       adj[v].push_back({u,w});
    }

    //create key array for storing minimum weight...
    vector<int> key(n+1);
    //create mst array to mark visited ...
    vector<bool> mst(n+1);

    //Create a Data structure for storing parent...
    vector<int> parent(n+1);

    for(int i=0;i<=n;i++){
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;
    }

    //Algo Starts...
    key[1]=0;
    parent[1]=-1;

    for(int i=1;i<n;i++){
        int mini=INT_MAX;
        int u;

       //find the minimum node from the key vector...
       for(int j=1;j<=n;j++){
           if(mst[j]==false && key[j]<mini){
               u=j;
               mini=key[j];
           }
       }

       //mark minimum node as true...
       mst[u]=true;

       //check it's adjacent nodes...
       for(auto it:adj[u]){
           int v=it.first;
           int w=it.second;

           if(mst[v]==false && w<key[v]){
               parent[v]=u;
               key[v]=w;
           }
       }
    }

    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
    }

    return ans;
}
