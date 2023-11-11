/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }
        vector<int> vec;
        int count = 0;
        getSum(root,vec,count,targetSum);
        return count;      

    }

    void getSum(TreeNode* root,vector<int> vec,int& count,int targetSum){
        if(root == NULL){
            return;
        }
        vec.push_back(root->val);
        getSum(root->left,vec,count,targetSum);
        getSum(root->right,vec,count,targetSum);
        int n = vec.size();
        long long sum = 0;
        for(int i=n-1;i>=0;i--){
            sum += vec[i];
            if(sum == targetSum){
                ++count;
            }
        }
    }
};
// @lc code=end

