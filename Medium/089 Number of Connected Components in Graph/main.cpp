class Solution {
public:
    int find(int node, vector<int> parent) { 
        if(parent[node] == node) return node;
        return find(parent[node], parent);
    }
    int unionfind(int node1, int node2, vector<int> &parent, vector<int> &rank) {
        int parent1 = find(node1, parent);
        int parent2 = find(node2, parent);
        if(parent1 == parent2) return 0;
        if(rank[parent2] > rank[parent1]) {
            parent[parent1] = parent2;
            rank[parent2] += rank[parent1];
        } else {
            parent[parent2] = parent1;
            rank[parent1] += rank[parent2];
        }
        return 1;
    }
    int countComponents(int n, vector<vector<int> > &edges) {
        vector<int> parent(n, 0);
        vector<int> rank(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
        int res = n;
        for (auto edge : edges) res -= unionfind(edge[0], edge[1], parent, rank);
        return res;
    }
};