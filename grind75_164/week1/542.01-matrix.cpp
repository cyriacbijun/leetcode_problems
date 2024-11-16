/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
    // int check_zero(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
    //     if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size()) {
    //         return 10000;  // Out of bounds, return a large value.
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     else if(mat[i][j] == 0){
    //         dp[i][j] = 0;
    //         return 0;
    //     }
       
    //     dp[i][j] = 1+ min({check_zero(i,j+1,mat,dp),check_zero(i,j-1,mat,dp),check_zero(i+1,j,mat,dp),check_zero(i-1,j,mat,dp)});
    //     return dp[i][j];
    // }
    // vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    //     int m = mat.size();
    //     int n = mat[0].size();
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     for(int i =0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             check_zero(i,j,mat, dp);
    //         }
    //     }
    //     return dp;
    // }

    // Should use BFS instead of DFS here

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty())
            return {};

        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> queue;
        int MAX_VALUE = m * n;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    queue.push({i, j});
                } else {
                    mat[i][j] = MAX_VALUE;
                }
            }
        }
        
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!queue.empty()) {
            auto [row, col] = queue.front(); queue.pop();
            for (auto [dr, dc] : directions) {
                int r = row + dr, c = col + dc;
                if (r >= 0 && r < m && c >= 0 && c < n && mat[r][c] > mat[row][col] + 1) {
                    queue.push({r, c});
                    mat[r][c] = mat[row][col] + 1;
                }
            }
        }
        
        return mat;
    }
};
// @lc code=end

