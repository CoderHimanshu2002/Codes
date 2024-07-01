//check evry component of the graph using BFS algorithm...
bool chkComponents(int node,int v,vector<int> adj[],vector<int> &color){

      // create a queue data structure...
      queue<int> q;
      //push starting node into it...
	    q.push(node);
      //Assign a color to starting node let's say '0'...
	    color[node]=0;

      //iterate while the queue 'q' is not empty...
	    while(!q.empty()){
	        int front=q.front();
	        q.pop();

          //iterate for the neighbour nodes, to check whether any adjdacent node has same color as front? or if any adjacent,
          // node is not colored , simply color it with opposite color of front node...
	        for(auto neighbour:adj[front]){

              //if neighbour has same color as the front node, simply return false...
	            if(color[neighbour]==color[front]){
	                return false;
	            }

              //if the neighbour node is uncolored , simply color it with opposite color of front node...
	            else if(color[neighbour]==-1){
	                color[neighbour]=!color[front];
	                q.push(neighbour);
	            }
	            
	        }
	    }

      //queue got empty , i.e everything got right , simply just return true...
	    return true;
    }


	bool isBipartite(int V, vector<int>adj[]){
	    // Code here

      //create a array to store color of every node of the given graph...
	    vector<int> color(V,-1);

      //loop to check for every components of the graph...
	    for(int i=0;i<V;i++){
          //if any node is uncolored then only proccess it...
	        if(color[i]==-1){
	            if(chkComponents(i,V,adj,color) == false){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}
