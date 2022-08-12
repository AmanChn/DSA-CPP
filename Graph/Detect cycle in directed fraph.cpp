#include <bits/stdc++.h>
using namespace std;

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
	   
	    
	    int count = 0;
	    
	    while( !q.empty() ){
	        int node = q.front();
	        q.pop();
	        
	        // jis element ko queue se nikal rhe ho usko ans mei bhi add kardo
	        count++;
	        for( auto i : adj[node] ){  // check for all adjacent nodes
	            indegree[i]--;   // decrease the indegree of adjacnet elements
	            if(indegree[i] == 0){
	                q.push(i);   // if degree becomes 0 push in queue.
	            }
	        }
	    }
	  
	  // topology sort is nothing but linear order of vertices, so if our count == V it means topology sort is found		  
          if(count == V)
		return false;	  
 
	  return true;
}

int main()
{
    // as topology sort can be found for only directed acyclic graph, we will use this property to find if there is cycle or not
    // if we can find the topology sort then there us no cycle.
   
    bool ans = cyclekahnAlgo(n,adj);
    
    if(ans)
	cout<<"Cycle exist"<<endl;
    else
	cout<<"Cycle dont exist"<<endl;


    return 0;
}
