/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( root == nullptr || root == p || root == q ) return root;

        TreeNode* left =  lowestCommonAncestor(root -> left, p ,q);
        TreeNode* right = lowestCommonAncestor( root -> right, p, q);

        if( left && right) return root; // both roots are not null
        else if ( left == nullptr) return right;//left is null
        else return left;// right is null
    }
};
// @lc code=end

