class Solution {
public:
    int find(int n, vector<int> &p) {
        if(p[n] == n) return n;
        p[n] = find(p[n], p);
        return p[n];
    }
    bool unionfind(int n1, int n2, vector<int> &p, vector<int> &rank) {
        int p1 = find(n1, p);
        int p2 = find(n2, p);
        if(p1 == p2) return false;
        if(rank[p2] > rank[p1]) swap(p1, p2);
        p[p2] = p1;
        rank[p1] += rank[p2];
        return true;
    }
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        vector<int> p(n, 0);
        vector<int> rank(n, 1);
        for(int i=0; i<n; i++) p[i] = i;
        for(auto edge: edges) if(!unionfind(edge[0], edge[1], p, rank)) return false;
        return edges.size() == n-1;
    }
};