
void bfs(vector<vector<int>> &adj,unordered_map<int,bool> &visited,
             vector<int> &ans,int node){

                 queue<int> q;
                 q.push(node);
                 visited[node]=1;

                 while(!q.empty()){
                     int frontNode=q.front();
                     ans.push_back(frontNode);
                     q.pop();
                    
                     for(int i=0;i<adj[frontNode].size();i++){
                         if(!visited[adj[frontNode][i]]){
                             q.push(adj[frontNode][i]);
                             visited[adj[frontNode][i]]=1;
                         }
                     }
                 }
             }

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<int> ans;
    unordered_map<int,bool> visited;

   /* for(int i=0;i<n;i++){
      if(!visited[i]){
          bfs(adj,visited,ans,i);
      }
    }*/

    bfs(adj, visited, ans, 0);

    return ans;
}
