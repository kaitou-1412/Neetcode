class Solution {
public:
    int bellmanFord(int n, int src, int dst, vector<vector<int>>& flights, int k) {
        // distance till previous no. of hops
        vector<int> prev(n, INT_MAX);
        prev[src] = 0;
        
        for(int i = 0; i <= k; i++) {
            // distance with curr hop
            vector<int> curr(prev);
            for(auto flight: flights) {
                // the curr dist value depends on the previous min dist data 
                // and so if we find a better dist, that means we are doing +1 hop
                // over the last iteration
                curr[flight[1]] = min(curr[flight[1]], 
                                      prev[flight[0]] == INT_MAX ? INT_MAX : prev[flight[0]] + flight[2]);
            }
            // make the distances with k hops as prev for the next iteration
            prev = move(curr);
        }
        return prev[dst] == INT_MAX ? -1 : prev[dst];
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // create the graph
        // <node, [<neighbor, cost>] >
        unordered_map<int, vector<pair<int, int> > > g;
        for(int i = 0; i < n; i++)
            g[i] = vector<pair<int, int>>{};
        
        for(auto flight: flights) 
            // add the edge with cost
            g[flight[0]].emplace_back(make_pair(flight[1], flight[2]));
        
        // return djikstraCost(src, dst, g, k);
        return bellmanFord(n, src, dst, flights, k);
    }
};