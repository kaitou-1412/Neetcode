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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool res = true;
        int leftHeight, rightHeight, diff;
        while(!q.empty()) {
            TreeNode* node = q.front();
            leftHeight = maxDepth(node->left);
            rightHeight = maxDepth(node->right);
            diff = rightHeight - leftHeight;
            if(-1 > diff || diff > 1 ) {
                res = false;
                break;
            }
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return res;    
    }
};