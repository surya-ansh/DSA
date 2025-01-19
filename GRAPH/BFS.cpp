ector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int n = adj.size();
        
        vector<int> vis(n, 0);
        
        vector<int> bfs;
        
        queue<int> q;
        q.push(0);
        
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            bfs.push_back(node);
            
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        
        return bfs;
    }




    class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();
        long long cost = 0;
        
        
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        
        for (int i = 0; i < n; i++) {
            cost += abs(arr[i] - brr[i]);  
        }

        
        if ((arr[0] > 0 && brr[0] < 0) || (arr[0] < 0 && brr[0] > 0)) {
            cost += k;  
        }

        
        return cost;
    }
};