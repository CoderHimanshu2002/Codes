#include <bits/stdc++.h> 

void sortTopological(int node,unordered_map<int,list<int>> &adj,vector<bool> &visited
                        ,stack<int> &s){
                            visited[node]=1;
                            for(auto neighbour:adj[node]){
                                if(!visited[neighbour]){
                                    sortTopological(neighbour,adj,visited,s);
                                }
                            }

                            s.push(node);
                        }

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adj;
    vector<int> ans;

    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

   // unordered_map<int,bool> visited(v);
    vector<bool> visited(v,false);
    stack<int> s;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            sortTopological(i,adj,visited,s);
        }
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}
