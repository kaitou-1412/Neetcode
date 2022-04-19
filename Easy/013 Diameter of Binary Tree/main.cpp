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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = INT_MIN;
        while(!q.empty()) {
            TreeNode* node = q.front();
            res = max(res, maxDepth(node->left) + maxDepth(node->right));
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return res;
    }
};