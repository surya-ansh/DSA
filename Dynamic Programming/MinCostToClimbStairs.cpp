class Solution {
    public:
    // recursion method
        int recursion(vector<int> &dp, int n, vector<int> &cost){
            if(n==0) return cost[0];
            if(n==1) return cost[1];
    
            if(dp[n] != -1) return dp[n];
    
            dp[n] = cost[n] + min(recursion(dp, n-1, cost), recursion(dp, n-2, cost));
    
            return dp[n];
        }
    
        // tabluation method
        int recursion2(int n, vector<int> &cost){
            vector<int> dp(n+1);
            dp[0] = cost[0];
            dp[1] = cost[1];
    
            for(int i=2; i<n; i++){
                dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
            }
    
            return min(dp[n-1], dp[n-2]);
        }
        int minCostClimbingStairs(vector<int>& cost) {
            // recursion method:-
            int n = cost.size();
            vector<int> dp(n+1, -1);
            int ans = min(recursion(dp, n-1, cost), recursion(dp, n-2, cost));
            return ans;
    
            // tabulation method:-
            int n = cost.size();
    
            return recursion2(n, cost);
        }
    };