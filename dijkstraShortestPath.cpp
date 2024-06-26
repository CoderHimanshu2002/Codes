#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //creating adjacency list...
    unordered_map<int,list<pair<int,int>>> adj;

    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //creating distance vector intialized infinity...
    vector<int> dist(vertices,INT_MAX);
 
    //creating set of type(distance,node)...
    set<pair<int,int>> st;

    dist[source]=0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        //fetch top record...

        auto top= *(st.begin());

        int nodeDistance=top.first;
        int topNode=top.second;

        //remove top record now...
        st.erase(st.begin());

        //traverse on the neighbours...

        for(auto neighbour:adj[topNode]){
            if(nodeDistance+neighbour.second < dist[neighbour.first]){
                auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));

                //if record found then erase it...
                if(record!=st.end()){
                    st.erase(record);
                }

                //Distance update...
                dist[neighbour.first]=nodeDistance+neighbour.second;

                //Record push into set...
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
        
    }

    return dist;
}
