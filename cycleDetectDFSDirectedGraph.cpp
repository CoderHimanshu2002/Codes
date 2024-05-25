#include<unordered_map>
#include <list>


bool cylceDetect(int node,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited
                           ,unordered_map<int,bool> &dfsVisited){
                            
                            visited[node]=1;
                            dfsVisited[node]=1;

                            for(auto neighbour:adj[node]){
                              if(!visited[neighbour]){
                                  bool cylceDetected=cylceDetect(neighbour, adj, visited,dfsVisited);
                                  if(cylceDetected){
                                    return true;
                                  }
                              }
                              else if(dfsVisited[neighbour]){
                                  return  true;
                              }
                            }
                            
                            dfsVisited[node]=false;
                            return false;

                           }

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  unordered_map<int,list<int>> adj;

  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;

    adj[u].push_back(v);
  }

  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsVisited;

  for(int i=0;i<n;i++){
     if(!visited[i]){
       bool ans= cylceDetect(i,adj,visited,dfsVisited);
       if(ans){
         return true;
       }
     }
  }
  return false;
}
