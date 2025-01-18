bool isCycle(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, 0);

    // Check each connected component
    for (int start = 0; start < n; start++)
    {
        if (!vis[start])
        {
            queue<pair<int, int>> q;
            q.push({start, -1});
            vis[start] = 1;

            while (!q.empty())
            {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        vis[it] = 1;
                        q.push({it, node});
                    }
                    else if (parent != it)
                    {
                        // means it visited to hai but parent nahi hai agar koi visited hai dubara 
                        // aaya wo bhi not as parent that means circular the graph is
                        return true;
                    }
                }
            }
        }
    }
    // No cycle detected in any component
    return false;