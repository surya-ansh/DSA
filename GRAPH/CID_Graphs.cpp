// // Algorithm:-

// 1.we are taking two arrays visited and pathVisited 
// Visited will track the nodes
// and pathVisited will track the path we are going to
// if the pathVis and visited are true for a node that means cycle has been found

// // we cannnot say cycle is present even we found the cycle but on two different paths like
// 1->2->3(3to5)
//    |  |
//    4->5
// (4 to 5 and 2 to 4) but not 4 to 5 thats y cycle is not present


private:
        
        bool dfsCheck(vector<vector<int>> adj, vector<int> &vis, vector<int> &pathVis, int i){
            vis[i] = 1;
            pathVis[i] = 1;
            
            for(auto it : adj[i]){
                if(!vis[it]){
                    if(dfsCheck(adj, vis, pathVis, it) == 1) return true;
                }
                else if(pathVis[it] == 1){
                    return true;
                }
                
            }
            
            // we want the path of i to be zero when we going back
            // as we move to another part it will not give true;
            pathVis[i] = 0;
            return false;
        }
        
        
        
  public:
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfsCheck(adj, vis, pathVis, i) == 1) return true;
            }
        }
        
        return false;
    }



    // BFS

    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> indegree(V,0);
        
        queue<int> q;
        
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            cnt++;
            
            for(auto it : adj[node]){
                indegree[it]--;
                
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        return cnt != V;
    }