/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*> &mp) {
        vector<Node*> neighbour;
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for(auto it: node->neighbors) {
            if(mp.find(it) != mp.end())   //already clone and stored in map
                neighbour.push_back(mp[it]);    //directly push back the clone node from map to neigh
            else
                neighbour.push_back(dfs(it,mp));
        }
        clone->neighbors = neighbour;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(node->neighbors.size() == 0) {
            Node* res = new Node(node->val);
            return res;
        }
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};