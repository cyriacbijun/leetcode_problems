/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return nullptr;
        }
        if(key > root->val){
            root->right = deleteNode(root->right,key);
            return root;
        }
        else if(key < root->val){
            root->left = deleteNode(root->left,key);
            return root;
        }
        else if(key == root->val){
            if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode* succParent = root;
                TreeNode* succ = root->right;
                while(succ->left != nullptr){
                    succParent = succ;
                    succ = succ->left;
                }
                if(succParent != root){
                    succParent->left = succ->right;
                }
                else{
                    succParent->right=succ->right;
                }
                root->val = succ->val;
                delete succ;
                return root;
            }
        }
        return root;
    }
};
// @lc code=end

