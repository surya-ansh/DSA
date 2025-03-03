class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // If the starting or ending cell is blocked, return -1
        if (n == 0 || grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        pair<int, int> src = {0, 0};
        pair<int, int> dest = {n - 1, n - 1};

        // Queue to store distance and coordinates
        queue<pair<int, pair<int, int>>> q;

        // Distance matrix initialized to a very high value
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[src.first][src.second] = 1;  // Start distance as 1

        q.push({1, {src.first, src.second}});

        // Possible directions to move in 8 directions
        vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 1}, {1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // Iterate over all 8 possible directions
            for (auto dir : directions) {
                int row_ = row + dir[0];
                int col_ = col + dir[1];
                int dis_ = 1;

                // Check bounds, unvisited, and if the cell is traversable
                if (row_ >= 0 && col_ >= 0 && row_ < n && col_ < n && grid[row_][col_] == 0 && dis + dis_ < dist[row_][col_]) {
                    q.push({dis + dis_, {row_, col_}});
                    grid[row_][col_] = 1;  // Mark as visited
                    dist[row_][col_] = dis + dis_;
                }
            }
        }

        // Check if destination is reachable
        if (dist[dest.first][dest.second] == 1e9) {
            return -1;
        }

        return dist[dest.first][dest.second];
    }
};
