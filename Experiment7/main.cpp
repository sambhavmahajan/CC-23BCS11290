class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto &flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        queue<pair<int, int>> q;
        vector<int> costs(n, INT_MAX);
        costs[src] = 0;
        q.push({src, 0});
        int stops = 0;
        while(!q.empty() && stops <= k) {
            int sz = q.size();
            while(sz-- > 0) {
                pair<int, int> p = q.front(); q.pop();
                for(auto &[nei, cost] : graph[p.first]) {
                    if(p.second + cost < costs[nei]) {
                        costs[nei] = p.second + cost;
                        q.push({nei, costs[nei]});
                    }
                }
            }
            stops++;
        }
        if(costs[dst] != INT_MAX) return costs[dst];
        return -1;
    }
};
