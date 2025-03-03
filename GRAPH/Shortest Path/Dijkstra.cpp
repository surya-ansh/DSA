// using priority queue 
// mean heap
// O(ElogV)
// E = edges V = vertices


// dijkstra's algorithm using priority queue

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        // min heap -> priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        // {distance, node}
        pq.push({0, src});
    
        while (!pq.empty()) {

            // to access the top element of a priority queue -> pq.top() not pq.front();
            int curDist = pq.top().first;
            int curNode = pq.top().second;
            pq.pop();
    
            if (curDist > dist[curNode]) continue;
    
            for (auto it : adj[curNode]) {
                int edgeWt = it.second;
                int nbd = it.first;
                // if the distance of the node is less than the current distance + edge weight
                if (edgeWt + curDist < dist[nbd]) {
                    dist[nbd] = curDist + edgeWt;
                    pq.push({dist[nbd], nbd});
                }
            }
        }
    
        return dist;
    }




// Dijkstra's Algorithm using set

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        
        set<pair<int,int> > s;
        
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        
        s.insert({0,src});
        
        while(!s.empty()){
            // top element of the set
            // {distance, node}
            auto top = *s.begin();
            int node = top.second;
            int currDis = top.first;
            s.erase(s.begin());
            
            for(auto it : adj[node]){
                int nbd = it.first;
                int edgeWt = it.second;
                
                if(currDis + edgeWt < dist[nbd]){
                    dist[nbd] = currDis + edgeWt;
                    s.insert({dist[nbd], nbd});
                }
            }
        }
        
        return dist;
    }