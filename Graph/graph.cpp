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

vector<int> bfsTraversal(vector<int> adj[] , int v){
     vector<int> bfs; // store bfs
     vector<bool> visited(v , false);  // to keep track of vivited elements
     
     for( int  i=0 ; i<v ;i++){  // loop if there are multiple components of graph (disconnected graph)
         if( !visited[i]){
             
             // start bfs process
             queue<int> q;
             q.push(i);
             visited[i] = true;
             
             while( !q.empty() ){
                 int frontNode = q.front();
                 q.pop();
                 
                 bfs.push_back(frontNode);
                 
                 for(auto it : adj[frontNode]){
                     if( !visited[it] ){
                         q.push(it);
                         visited[it] = true;
                     }
                 }
             }
             
         }
     }
     
    return bfs; 
}


void dfsCalls(vector<int> adj[] , vector<bool> &visited , vector<int> &dfs , int node){
    
    dfs.push_back(node);
    visited[node] = true;
    
    for(auto it : adj[node]){
        if( !visited[it]){
            dfsCalls(adj,visited,dfs,it);
        }
    }
}

vector<int> dfsTraversal(vector<int> adj[] , int v ){
    vector<int> dfs ; 
    vector<bool> visited(v , false);
    
    for(int i=0 ; i<v ; i++){  // loop if there are multiple components of graph (disconnected graph)
        if( !visited[i] ){
            dfsCalls(adj , visited , dfs , i);
        }
    }
    return dfs;
}

void printVector(vector<int> vect){
    for( auto i : vect){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
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
    
    vector<int> BFS = bfsTraversal(adj , n);

    cout<<"BFS traversal : ";
    printVector(BFS);
    
    
    vector<int> DFS = dfsTraversal(adj , n);
    cout<<"DFS traversal : ";
    printVector(DFS);
    
    return 0;
}
