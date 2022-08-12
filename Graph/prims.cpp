
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


// tc: O(n2)
void primsBrute(vector<pair<int,int>> adj[], int V){
    
    vector<int> key(V , INT_MAX);
    vector<int> parent(V , -1);
    vector<bool> mstSet(V , false);
    
    key[0]= 0;
    parent[0] = -1;
    
    for( int i=0 ; i<V-1 ; i++){ // as min spanning tree has v-1 edges
        // Pick the minimum key vertex from the 
        // set of vertices not yet included in MST
        int u , mini = INT_MAX;
        
        for( int i=0 ; i<V ; i++){
            if( mstSet[i] == false && key[i] < mini ){
                mini = key[i];
                u = i;
            }
        }
        
        mstSet[u] = true;
        
        for( auto it : adj[u]){
            int v = it.first;
            int weight = it.second;
            if( mstSet[v] == false && weight < key[v]){
                parent[v] = u;
                key[v] = weight;
            } 
        }
        
    }
    
    for( int i= 1 ; i<V ; i++){
        cout<<parent[i]<<" - "<<i<<endl; 
    }

}

// TC : O(nlogn )
void primsOptimized(vector<pair<int,int>> adj[], int V){
    
    vector<int> key(V , INT_MAX);
    vector<int> parent(V , -1);
    vector<bool> mstSet(V , false);
    
    priority_queue<pair<int,int> ,vector<int,int> , greater<pair<int,int>> > minHeap;

    key[0]= 0;
    parent[0] = -1;
    minHeap.push({ 0,0 });  // store key[i] : index
    
    for( int i=0 ; i<V-1 ; i++){ // as min spanning tree has v-1 edges
        // Pick the minimum key vertex from the 
        // set of vertices not yet included in MST
        
        int u = minHeap.top().second;  
        pq.pop();

        mstSet[u] = true;
        
        for( auto it : adj[u]){
            int v = it.first;
            int weight = it.second;
            if( mstSet[v] == false && weight < key[v]){
                parent[v] = u;
                key[v] = weight;
                minHeap.push({ key[v],u })
            } 
        }
        
    }
    
    for( int i= 1 ; i<V ; i++){
        cout<<parent[i]<<" - "<<i<<endl; 
    }

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

    
    /*  
        5 6
        0 1 2
        0 3 6
        1 2 3 
        1 3 8 
        1 4 5 
        2 4 7

        
    */
    
    cout<<"minimum spanning tree using prims algo : "<<endl;
    // primsBrute(adj,V);
    prims(adj,V);

    return 0;
}
