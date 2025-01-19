   void dfs(int i, vector<vector<pair<int, int>>>& adj, vector<int>& vis, stack<int>& st) {
    vis[i] = 1;
    for (auto it : adj[i]) {
        int node = it.first;
        if (!vis[node]) {
            dfs(node, adj, vis, st);
        }
    }
    st.push(i);
}

vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(V);
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v, wt});
    }

    vector<int> vis(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    vector<int> dis(V, 1e9);
    dis[0] = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

            for (auto it : adj[node]) {
                int u = it.first;
                int wt = it.second;
                if (dis[node] + wt < dis[u]) {
                    dis[u] = dis[node] + wt;
                }
            }
        
    }
    
    vector<int> ans;
    for(auto it : dis){
        if(it == 1e9){
            ans.push_back(-1);
        }
        else{
            ans.push_back(it);
        }
    }
    return ans;
}
