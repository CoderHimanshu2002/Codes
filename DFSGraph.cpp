void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adjList,
            vector<int> &component)
            {
              //ans store...
              component.push_back(node);
              //mark visited...
              visited[node]=true;
              
  
              //For every connected node a recursive call...
              for(auto i:adjList[node]){
                  if(!visited[i]){
                      dfs(i,visited,adjList,component);
                  }
              }
            }

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // prepare Adj List...
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<E;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;

    //For all node call dfs if not visited...
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,visited,adjList,component);
            ans.push_back(component);
        }
    }

    return ans;
}
