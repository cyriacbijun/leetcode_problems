/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
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
    int maxLevelSum(TreeNode* root) {
        queue<pair<int,TreeNode*>> q;
        map<int,int> mp;
        q.push({1,root});
        while(!q.empty()){
            TreeNode* temp = q.front().second;
            int level = q.front().first;
            if(mp.find(level) != mp.end()){
                mp[level] += temp->val;
            }
            else{
                mp[level] = temp->val;
            }
            if(temp->left != NULL){
                q.push({level+1,temp->left});
            }
            if(temp->right != NULL){
                q.push({level+1,temp->right});
            }
            q.pop();
        }
        int maxElement  = root->val;
        int maxLevel = 1;
        for(auto item:mp){
            cout<<item.second<<endl;
            if(item.second > maxElement){
                maxElement = item.second;
                maxLevel = item.first;
            }
        }
        return maxLevel;
    }
};
// @lc code=end

