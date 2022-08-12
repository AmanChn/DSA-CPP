#include <bits/stdc++.h>
using namespace std;

// program to find the sortest distence of all nodes from given node

void addEdge(vector<int> adj[] , int u , int v , bool direction){
    // direction 1 = directed graph
    if(direction){
        adj[u].push_back(v);
    }
    else{
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void printVector(vector<int> vect){
    for(auto i : vect){
        cout<<i<<" ";
    }
    cout<<endl;
}

void shortDist(vector<int> adj[] , int source , int V){
    vector<int> dist(V , INT_MAX);
    queue<int> q;
    
    dist[source] = 0;  // sourfe ka distance from itself
    q.push(source);
    
    while( !q.empty() ){
        int node = q.front();
        q.pop();
        
        for( auto it : adj[node]){
            
            if( dist[node] + 1 < dist[it] ){
                dist[it] = dist[node] + 1;
                q.push(it);
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
    vector<int> adj[V];
    
    for( int i=0 ; i<E ; i++){
        int u,v;
        cout<<"Enter the edge btw vertices: ";
        cin>>u>>v;
        
        addEdge(adj,u,v,0);
    }
    
    int source;
    cout<<endl<<"Enter the source vertex : ";
    cin>>source;
    
    // vector<int> shortestdist = shortDist(adj,source,V);
    
    cout<<"Distance of each vertex from source is : "<<endl;
    // printVector(shortestdist);
    shortDist(adj,source,V);

    return 0;
}
