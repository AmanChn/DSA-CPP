vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V , INT_MAX);
        // using min heap as its top will always comtain min value
        priority_queue< pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>> > minHeap;
        
        dist[S] = 0;
        
        minHeap.push( { 0,S } );  // distance : from node
        
        while( !minHeap.empty() ){
            int distance = minHeap.top().first;  // distance from source to this node
            int topNode = minHeap.top().second;  
            
            minHeap.pop();
            
            for( auto it : adj[topNode] ){  // all neightbour of topNode
                int next = it[0];
                int nextdist = it[1];
                
                // distance = distance from source to parent node ; it.sec = distance from parent to this node 
                if( dist[next] > distance + nextdist ){  // if we can find a shorter path then update it
                    dist[next] = dist[topNode] + nextdist;
                    minHeap.push({dist[next], next});
                 }
            }
        }
        return dist;
    }