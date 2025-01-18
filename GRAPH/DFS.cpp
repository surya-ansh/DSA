void dfs(vector<int> &ans, int i, vector<int> &vis, vector<vector<int>> adj){
        ans.push_back(i);
        vis[i] = 1;
        
        for(auto it : adj[i]){
            if(!vis[it]){
                dfs(ans, it, vis, adj);
            }
        }
    }
    
    
    
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n = adj.size();
        // visited array to track the nodes
        vector<int> vis(n,0);
        vector<int> ans;
        

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(ans, i, vis, adj);
            }
        }
        
        return ans;
    }

    // in this basically we have to traverse through all the neighbours of the node 
    like we are starting from 0;
    0 ka first nbd then nbd ka nbd jab tk end na ho (going into depth)
    0 ka second nbd then uska nbd and so on
    0 ka thirs nbd then uska nbd and so on