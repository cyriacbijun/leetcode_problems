/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafNodes1;
        getLeaf(root1,leafNodes1);
        vector<int> leafNodes2;
        getLeaf(root2,leafNodes2);
        if(leafNodes1 == leafNodes2){
            return true;
        }
        return false;
    }

    void getLeaf(TreeNode* root,vector<int>& leafNodes){
        if(root->left == NULL && root->right == NULL){
            leafNodes.push_back(root->val);
        }
        else{
            if(root-> left != NULL)
            getLeaf(root->left,leafNodes);
            if(root-> right != NULL)
            getLeaf(root->right,leafNodes);
        }
    }
};
// @lc code=end

