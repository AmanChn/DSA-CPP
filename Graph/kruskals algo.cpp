// kruskals algo

#include <bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    
    node(int first , int second , int weight){
        u = first;
        v = second;
        wt = weight;
    }
};


int findParent(int node , vector<int> &parent){
    if(node == parent[node])
        return node;
    
    // 7->6->3->1
    
    // compression : update the parent of all to the highest parent
    return parent[node] = findParent(parent[node] , parent);  // find parent until base cond reaches
}


void unionn(int u ,int v , vector<int> &parent , vector<int> &rank){
    u = findParent(u,parent);
    v = findParent(v,parent);
    
    if( rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else{  // if equal rank
        parent[u] = v; // we can select anyone
        rank[u]++;     // if equal rank then depth will incresae so increase the rank of parent
    }
    
}

bool comp(node a , node b){
    return a.wt<b.wt;
}

int main()
{
    
    int N , E;
    cin>>N>>E;  // input vertices and edges
    
    /*
        6 9 
        5 4 9
        5 1 4
        4 1 1
        4 3 5
        4 2 3
        1 2 2
        3 2 3
        3 6 8
        2 6 7
    
    */
    
    vector<node> edges;  // make a vector of struct node containing 2 edges and weight
    for(int i=0 ; i<E ; i++){
        int u , v, wt;
        cin>>u>>v>>wt;
        
        edges.push_back(node(u,v,wt));  // push edges into edges vector
    }
    
    sort(edges.begin() , edges.end() , comp);  // sort the array according to weight
    
    vector<int> parent(N+1); //of size = vertices
    for(int i=1 ;i<N ;i++){
        parent[i] = i;  // make every node its own parent
    }
    
    vector<int> rank(N+1,0); // initialize all rank with 0
    
    int cost = 0;
    
    vector<pair<int,int>> mst;  // sto store the min spamming tree
    
    for( auto it : edges ){
        if( findParent(it.u , parent) != findParent(it.v,parent) ){  // if they are of diff components
            cost += it.wt;  // find cost
            mst.push_back( { it.u , it.v } );  // add this pair to mst
            unionn(it.u , it.v , parent, rank );  // add them into same component
            // as we have sorted the vector acc to wt we will greedily take the shortest edge
        }
    }
    
    cout<<endl<<"cost of spanning tree is : "<<cost<<endl;
    
    for(auto i : mst){
        cout<<i.first<<" - "<<i.second<<endl;
    }
    
    return 0;
}
