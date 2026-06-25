//findBridge

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, unordered_map<int,bool> &visited,
             vector<vector<int>> &res, vector<int> adj[]){
		
	visited[node] = true;
        
        disc[node] = low[node] = timer++; //set the timer of each node
        
        // for all neighbors of curr node
        for( auto nbr : adj[node] ){
            if( nbr == parent ){  // dont do anything, as we came from parent only.
                continue;
            }
            
            if(!visited[nbr]){ // call dfs for each unvisited neighbor
                dfs(nbr,node,timer,disc,low,visited,res,adj); // parent will become curr node
                
                low[node] = min(low[node] , low[nbr]); // update low of curr node to min
                
                // check for bridge
                if( low[nbr] > disc[node] ){ // condition for bridge
                    res.push_back( {node,nbr} );  // bridge nodes
                }
            }
            else{ // if node is already visited
                // back edge i.e we have another path to reach our current node
                low[node] = min(low[node] , disc[nbr]); // update to min
            }
        }    

}


int main()
{
    int V,E;
    cout<<"vertices and edges: ";
    cin>>V>>E;
    
    vector<int> adj[V];
    
    for(int  i=0 ; i<E ; i++){
        int u,v;
        cout<<"enter edges btw : "
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    int timer=0;
    vector<int> discvTime(V);
    vector<int> lowTime(V);
    int parent = -1;
    unordered_map<int,bool> visited (V,false);
    
	vector<vector<int>> res;    

    //dfs
    for(int i=0 ; i<V; i++){
        if(!visited[i]){
            dfs(i,parent,timer,disc,low,visited,res,adj);
        }
    }
    

    
    return 0;
}
