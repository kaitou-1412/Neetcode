class Solution {
public:
    int find(int node, vector<int> parent){
        if(parent[node] == node) return node;
        return find(parent[node], parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        vector<int> parent(1001,0);
        for(int i=0; i<parent.size(); i++) parent[i] = i;
        vector<int> res;
        for(auto &edge: edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            int representative1 = find(node1, parent);
            int representative2 = find(node2, parent);
            if(representative1 == representative2) res = edge;
            parent[representative1] = representative2;
        }
        return res;
    }
};