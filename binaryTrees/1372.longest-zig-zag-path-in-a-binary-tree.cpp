/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
    int maxCount = 0;
public:
    int longestZigZag(TreeNode* root) {
        if(root->left == NULL && root->right == NULL){
            return 0;
        }
        zigZagCount(root,true,0);
        zigZagCount(root,false,0);
        return maxCount;
    }

    void zigZagCount(TreeNode* root, bool isNextRight, int count){
        if(root== NULL){
            return;
        }
        
            if(isNextRight){
                zigZagCount(root->left,true,1);
                zigZagCount(root->right,false,count + 1);
            }
            else{
                zigZagCount(root->left,true,count + 1);
                zigZagCount(root->right,false,1);
            }
        maxCount = max(count,maxCount);
    }
};
// @lc code=end

