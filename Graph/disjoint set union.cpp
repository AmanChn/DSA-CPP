
#include <bits/stdc++.h>
using namespace std;

int rank[10000];
int parent[10000];

void makeSet(){
    for(int i=1 ; i<=10000 ; i++){
        parent[i] = i;  // set parent of all to itself
        rank[i]=0;  // set all rank to 0;
    }
}


int findParent(int node){
    if(node == parent[node])
        return node;
    
    // 7->6->3->1
    
    // compression : update the parent of all to the highest parent
    return parent[node] = findParent(parent[node]);  // find parent until base cond reaches
}


void union(int u ,int v){
    u = findParent(u);
    v = findParent(v);
    
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

int main()
{
    makeSet();
    int m;
    cin>>m;
    while(m--){
        int u , v;
        cin>>u>>v;
        union(u , v);
    }
    

    return 0;
}
