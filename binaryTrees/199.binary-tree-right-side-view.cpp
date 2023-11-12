/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> elements;
        if(root == NULL){
            return elements;
        }
        queue<pair<TreeNode*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode *,int> temp = q.front();
            int level = temp.second;
            TreeNode* ptr = temp.first;
            mp[level] = ptr -> val;
            if(ptr -> left != NULL){
                q.push({ptr->left,level + 1});
            }
            if(ptr -> right != NULL){
                q.push({ptr->right,level + 1});
            }
            q.pop();
        }
        for(auto it:mp){
            elements.push_back(it.second);
        }
        return elements;
    }      
}; 
// @lc code=end

