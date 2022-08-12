#include <bits/stdc++.h>
using namespace std;

void printAdjList(vector<int> adj[] , int v){
    cout<<endl<<"Adjacency List is: "<<endl;
    for( int i =0 ; i<v ; i++){
        cout<<i<<"-> ";
        for(auto j : adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void addEdge(vector<int> adj[] , int u , int v, bool direction){
    // direction 0 => undirected
    // direction 1 => directed
    
    if( direction ){  // if directed grapoh then only make the edge for given direction
        adj[u].push_back(v);  
    }
    else{  // if undirected graph then add edge in both direction
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
}


vector<int> kahnAlgo(int V, vector<int> adj[]){
	    vector<int> indegree(V , 0); // to store the indegree of all nodes
	    queue<int> q;
	    
	    for( int i=0 ; i< V ; i++){
	        for( auto it : adj[i] ){  // in adjlist of directed graph each node has 
	            indegree[it]++;     // incident adjacent element
	        }                     // so this will increase the count of indegree
	    } 
	    
	    // push elements with 0 indegree into the queue
	    // as they cannot have any node before them (u->v)
	    for(int i=0 ; i<V ;i++){
	        if( indegree[i] == 0)
	            q.push(i);
	    }
	   
	    
	    vector<int> topo;
	    
	    while( !q.empty() ){
	        int node = q.front();
	        q.pop();
	        
	        // jis element ko queue se nikal rhe ho usko ans mei bhi add kardo
	        topo.push_back(node);
	        for( auto i : adj[node] ){  // check for all adjacent nodes
	            indegree[i]--;   // decrease the indegree of adjacnet elements
	            if(indegree[i] == 0){
	                q.push(i);   // if degree becomes 0 push in queue.
	            }
	        }
	    }
	    
	  return topo;
}


void printVector(vector<int> vect){
    for( auto i : vect){
        cout<<i<<" ";
    }
    cout<<endl;
}


int main()
{
    // if a graph can be colored by 2 different colors such that no 2 consecutive nodes have same color 
    // then its bipartite.
    // a graoh having odd lenght cycle is always non bipartite.
    int n , m ;
    cout<<"Enter no. of vertices and edges : ";
    cin>>n>>m;
    
    vector<int> adj[n+1];
    
    for(int  i = 0 ; i< m ; i++){
        int u ,v ;
        cout<<"Enter the connected edges : ";
        cin>>u>>v;

        addEdge(adj,u,v,1);  // 1 or 0 denotes directed or undirected graph
        
    }
    
    
    printAdjList(adj, n);
    
    vector<int> topo = kahnAlgo(n,adj);
    
    printVector(topo);


    return 0;
}
