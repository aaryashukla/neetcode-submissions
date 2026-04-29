class Solution {
public:
    int findCheapestPrice(int n,
                          vector<vector<int>>& flights,
                          int src,
                          int dst,
                          int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &it : flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        // {cost, node, stops}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<int> dist(n, INT_MAX);

        pq.push({0, src, 0});
        dist[src] = 0;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int cost = cur[0];
            int node = cur[1];
            int stops = cur[2];

            if (node == dst) return cost;

            if (stops > k) continue;

            for (auto &[nbr, wt] : adj[node]) {
                int newCost = cost + wt;

                if (newCost < dist[nbr] || stops < k) {
                    dist[nbr] = newCost;
                    pq.push({newCost, nbr, stops + 1});
                }
            }
        }

        return -1;
    }
};