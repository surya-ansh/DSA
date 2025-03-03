class Solution {
    public:
        int solve(vector<int>& values, int i, int j, vector<vector<int>> &dp){
            if(i+1 == j) return 0;
    
            if(dp[i][j] != -1) return dp[i][j];
    
            int minans = INT_MAX;
            for(int k = i+1; k<j; k++){
                int ans = values[i]*values[k]*values[j] + solve(values, i, k, dp) + solve(values, k, j, dp);
                minans = min(ans, minans);
            }
    
            return dp[i][j] = minans;
        }
        int minScoreTriangulation(vector<int>& values) {
            int n = values.size();
            vector<vector<int>> dp(n, vector<int> (n,-1));
            return solve(values, 0, n-1, dp);
        }
    };