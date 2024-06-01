#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int,list<int>> adj;
	for(int i=0;i<m;i++){
		int u=edges[i].first;
		int v=edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//do bfs

	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;
    parent[s]=-1;
	queue<int> q;
	q.push(s);
	visited[s]=1;

	while(!q.empty()){
		int front=q.front();
		q.pop();

		for(auto i:adj[front]){
			if(!visited[i]){
              visited[i]=1;
			  parent[i]=front;
			  q.push(i);
			}
		}
	}
	
	//backtrack the parent for answer...
	vector<int> ans;
	int currentNode=t;
	ans.push_back(t);
	while(currentNode!=s){
        currentNode=parent[currentNode];
		ans.push_back(currentNode);
	}
    reverse(ans.begin(),ans.end());

	return ans;
}
