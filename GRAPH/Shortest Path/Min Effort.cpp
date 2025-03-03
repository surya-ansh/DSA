class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // m = row and n = col
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == m - 1 && col == n - 1) {
                return diff;
            }

            for (auto dir : directions) {
                int row_ = row + dir[0];
                int col_ = col + dir[1];
                if (row_ >= 0 && col_ >= 0 && row_ < m && col_ < n) {
                    int diff_ = max(diff, abs(heights[row_][col_] - heights[row][col]));
                    if (diff_ < dist[row_][col_]) {
                        dist[row_][col_] = diff_;
                        pq.push({diff_, {row_, col_}});
                    }
                }
            }
        }

        return 0; 
    }
};
