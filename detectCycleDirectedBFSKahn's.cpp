int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  unordered_map<int,list<int>> adj;

  for(int i=0;i<edges.size();i++){
    int u=edges[i].first-1;
    int v=edges[i].second-1;
    
    adj[u].push_back(v);
  }

  // unordered_map<int,bool> visited;
  // unordered_map<int,bool> dfsVisited;

  // for(int i=0;i<n;i++){
  //    if(!visited[i]){
  //      bool ans= cylceDetect(i,adj,visited,dfsVisited);
  //      if(ans){
  //        return true;
  //      }
  //    }
  // }
  // return false;

   //calc indegree of every node...
    vector<int> indegree(n);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //Perform BFS
    //vector<int> ans;
    int cnt=0;

    while(!q.empty()){
        int front=q.front();
        q.pop();
    
        //ans store
       // ans.push_back(front);
        cnt++;
        //neighbour indegree update
        for(auto neighbour:adj[front]){
             indegree[neighbour]--;
             if(indegree[neighbour]==0){
                 q.push(neighbour);
             }
        }
    }

   //If valid topological sort then cycle is not present...otherwise present...
   if(cnt==n){
     return false;
   }

   return true;
}
