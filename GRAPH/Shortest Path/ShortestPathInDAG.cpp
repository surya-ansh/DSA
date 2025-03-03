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

    // preparing adjacancy list 
    // as the graph is directed so we will take pair of int and int
    vector<vector<pair<int, int>>> adj(V);
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v, wt});
    }

    vector<int> vis(V, 0);
    // taking stack here
    // as we have to traverse the graph in topological order
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
                // this is the way to check if the node is reachable or not
                // intially we have stored the distance of all the nodes as 1e9
                // so if the node is not reachable then the distance will be 1e9
                // so we will not go in the if condition
                // if the node is reachable then we will go in the if condition
                if (dis[node] + wt < dis[u]) {
                    dis[u] = dis[node] + wt;
                }
            }
        
    }
    // preparing the ans vector
    // if the distance of the node is 1e9 then the node is not reachable
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
