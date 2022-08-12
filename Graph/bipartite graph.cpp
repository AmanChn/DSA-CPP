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

bool isBipartiteBfs(vector<int> adj[] , int color[] , int start ){
        color[start] = 0;
        
        queue<int> q; 
        q.push(start);
        
        while( !q.empty() ){
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                if( color[it] == -1){
                    if(color[node] == 0)  // set opposite color of the previous node
                        color[it] = 1;
                    else
                        color[it] = 0;  
                        
                    q.push(it);
                }
                else if( color[node] == color [it]){
                    return false;
                }
            }
            
        }
        return true;
    }


bool isBipartiteDfs(vector<int> adj[] , int color[] , int start){
        if(color[start] == -1){
            color[start] = 0;
        }
        
        for(auto it : adj[start]){
            if( color[it] == -1 ){
                if(color[start] == 0)  // set opposite color of the previous node
                    color[it] = 1;
                else
                    color[it] = 0;  
                    
                if( !isBipartiteDfs(adj,color,it) ){  // if at any depth its not bipartite , complete graoh is not bipartite
                    return false;
                }
                
            }  // else if it was already colored 
            else if(color[it] == color[start]){  // it prev and curr have same color then it cant be bipartite
                return false;
            }
        }
        return true;
    }


bool isBipartite(int v, vector<int>adj[]){
	    int color[v];
	    memset(color, -1 , sizeof(color)); // initialize with -1
	    
	    for( int  i = 0 ; i<v ; i++){  // loop for all component of graph
	        if( color[i] == -1 ){
	            // using bfs
	           // if( !isBipartiteBfs(adj,color,i) ){  // if any one component is not bipartite then complete graph is not
	           //     return false;
	           // }
	           
	           // using dfs
	               if( !isBipartiteDfs(adj,color,i) ){  // if any one component is not bipartite then complete graph is not
	                return false;
	            }
	        }
	    }
	    return true;
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
    
    bool ans = isBipartite( n,adj);
    
    
    if(ans){
        cout<<"graph is bipartite"<<endl;
    }
    else{
        cout<<"graph is not bipartite"<<endl;
    }
    


    return 0;
}
