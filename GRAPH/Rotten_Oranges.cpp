class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> rotten;
        int cnt = 0, total = 0, days = 0;

        // m is number of rows and n = number of columns
        // but the iteration goes from 0 to n because if u write down the matrix on paper u find that iteration is happenning for rows then column and to iterate in rows we have to increase the value of rows
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) total++;
                if (grid[i][j] == 2) rotten.push({i, j});
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!rotten.empty()) {
            int size = rotten.size();
            cnt += size;

            while (size--) {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
                        continue;

                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }

            if (!rotten.empty()) days++;
        }

        return cnt == total ? days : -1;
    }
};
