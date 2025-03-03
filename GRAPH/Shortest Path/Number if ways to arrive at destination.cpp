#include <vector>
#include <queue>
#include <climits> // For LLONG_MAX
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = (int)(1e9 + 7);
        vector<vector<pair<int, int>>> adj(n);

        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        vector<long long> timeArray(n, LLONG_MAX);
        vector<int> ways(n, 0);
        timeArray[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0}); // {time, node}

        while (!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop();

            if (currTime > timeArray[node]) continue;

            for (auto& [neighbor, travelTime] : adj[node]) {
                long long newTime = currTime + travelTime;

                if (newTime < timeArray[neighbor]) {
                    timeArray[neighbor] = newTime;
                    pq.push({newTime, neighbor});
                    ways[neighbor] = ways[node];
                } else if (newTime == timeArray[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
