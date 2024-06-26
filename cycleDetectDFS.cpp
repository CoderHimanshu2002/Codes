bool cycleDetectDFS(int i,int parent,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited){

  visited[i]=true;

  for(auto neighbour:adj[i]){
      if(!visited[neighbour]){
         bool cycleDetect=cycleDetectDFS(neighbour,i,adj,visited);

         if(cycleDetect){
           return true;
         }
      }

      else if(neighbour!=parent){
        return true;
      }
  }

  return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m) {
  // Write your code here.
  unordered_map<int, list<int>> adj;

  for (int i = 0; i < m; i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  unordered_map<int, bool> visited;

  for (int i = 0; i < n; i++) {

    if (!visited[i]) {
      bool ans = cycleDetectDFS(i,-1, adj, visited);

      if (ans == 1) {
           return "Yes";
      }
    }
  }
  return "No";
}
