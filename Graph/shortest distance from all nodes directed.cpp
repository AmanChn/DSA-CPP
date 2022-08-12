
#include <bits/stdc++.h>
using namespace std;

// program to find the sortest distence of all nodes from given node in directed graph

void addEdge(vector<pair<int,int>> adj[] , int u , int v , int w, bool direction){
    // direction 1 = directed graph
    if(direction){
        adj[u].push_back({v,w});
    }
    else{
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
}

void printVector(vector<int> vect){
    for(auto i : vect){
        cout<<i<<" ";
    }
    cout<<endl;
}

void topoSort(vector<pair<int,int> > adj[] , vector<bool> visited , stack<int> &st , int node){
    visited[node] = true;
    
    for( auto it : adj[node]){
        if( !visited[it.first] ){
            topoSort(adj,visited,st,it.first);
        }
    }
    st.push(node);
}


void shortDistDirected(vector<pair<int,int> > adj[] , int source , int V){
    // find the topoSort
    // topological sort is done because it will make sure If the dag contains a path from vertex u to vertex v, 
    //then u precedes v in the topological sort. We make just one pass over the vertices in the topologically sorted order. 
    //As we process each vertex, we relax each edge that leaves the vertex.
    
    vector<bool> visited(V,false);
    stack<int> st;
    
    for( int i=0 ; i < V; i++){
        if( !visited[i]){
            topoSort(adj,visited,st,i);
        }
    }
    
    // now find the shortest distance
    
    
    vector<int> dist(V , INT_MAX);
    
    dist[source] = 0;  // source ka distance from itself

    while( !st.empty() ){
        int node = st.top();
        st.pop();
        
        if( dist[node] != INT_MAX ){
            for( auto it : adj[node]){
                
                if( dist[node] + it.second < dist[it.first] ){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }
    
    printVector(dist);
}


int main()
{
    int V,E;
    cout<<"Enter the Vertices and Edges: ";
    cin>>V>>E;
    vector<pair<int,int> > adj[V]; // adjacent vertex : weight 
    
    for( int i=0 ; i<E ; i++){
        int u,v,w;
        cout<<"Enter the edge btw vertices and weight: ";
        cin>>u>>v>>w;
        
        addEdge(adj,u,v,w,0);
    }
    
    int source;
    cout<<endl<<"Enter the source vertex : ";
    cin>>source;
    
    /*  
        6 7
        0 1 2
        0 4 1
        1 2 3 
        2 3 6 
        4 2 2 
        4 5 4
        5 3 1 
        
        
    */
    
    cout<<"Distance of each vertex from source is : "<<endl;
    shortDistDirected(adj,source,V);

    return 0;
}
