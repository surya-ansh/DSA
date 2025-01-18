class Solution {
public:

    bool dfs(vector<int> &color, vector<vector<int>>graph, int i, int col){
        color[i] = col;

        for(auto it : graph[i]){
            if(color[it] == -1){
                if(dfs(color, graph, it, 1-col) == false) return false;
            }
            else if(color[it] == col){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(dfs(color, graph, i, 0) == false ) return false;
            }
        }

        return true;
    }
};