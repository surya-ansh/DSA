class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int k = numCourses;

        vector<int> indegree(k);

        // preparing adjacency list
        vector<vector<int> > adj(k);

        for(auto node : prerequisites){
            int u = node[0];
            int v = node[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;

        for(int i=0; i<k; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                }
            }

        }
        
        if(ans.size() == numCourses) return ans;

        return {};
    }
};