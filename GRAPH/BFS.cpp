ector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int n = adj.size();
        // marking if the current node is visited
        vector<int> vis(n, 0);
        // answer vector
        vector<int> bfs;
        // pushing into queue
        queue<int> q;
        q.push(0);
        // marking the first element visited 
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            bfs.push_back(node);
            
            // checking if the node has been visited or not
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        
        return bfs;
    }