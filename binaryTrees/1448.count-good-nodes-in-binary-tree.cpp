/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
 */

// @lc code=start
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
    int goodNodes(TreeNode* root) {
        int count = 1;
        checkNode(root->left,root->val,count);
        checkNode(root->right,root->val,count);
        return count;
    }

    void checkNode(TreeNode* root,int greatestValue,int& count){
        if(root == NULL){
            return;
        }
        if(root -> val >= greatestValue){
            count++;
            greatestValue = root->val;
        }
        if(root->left != NULL)
        checkNode(root->left,greatestValue,count);
        if(root->right != NULL)
        checkNode(root->right,greatestValue,count);
    }
};
// @lc code=end

