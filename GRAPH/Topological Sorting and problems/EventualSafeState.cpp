class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

    // indegree store hogyi ans reverse vector bhi ban gaya
        vector<int> indegree(n,0);
        vector<vector<int> > ngraph(n);

        for(int i=0; i<n; i++){
            for(auto it : graph[i]){
                ngraph[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
    // queue me push kara diya terminal nodes;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

    vector<int> safeNode;

    // BFS
        while(!q.empty()){
            int node = q.front();
            q.pop();

            safeNode.push_back(node);

            for(auto it : ngraph[node]){
                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
         
        sort(safeNode.begin(), safeNode.end());

        return safeNode;

    }
};

algo :- 
graph reverse
prepare indegree array
push indegree == 0 into the queue
go through the queue and decrease the indegree and if becomes 0 then push it in the queue as well
