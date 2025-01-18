 vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> indegree(n,0);
        
        for(int i=0; i<n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int temp = q.front();
            
            q.pop();
            
            ans.push_back(temp);
            
            for(auto it : adj[temp]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);                }
            }
        }
        return ans;
    }