/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int fix, int &res) {
        if(!root) return;
        if(root && fix <= root->val) res++;
        fix = max(fix, root->val);
        solve(root->left, fix, res);
        solve(root->right, fix, res);
    }
    int goodNodes(TreeNode* root) {
        int res = 0, fix = INT_MIN;
        if(!root) return res;
        solve(root, fix, res);
        return res;
    }
};