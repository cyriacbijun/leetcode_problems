/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ++count;
                visitCities(visited, isConnected, i);
            }
        }
        return count;
    }

    void visitCities(vector<bool>& visited,vector<vector<int>>& isConnected,int currentCity){
        visited[currentCity] = true;
        int n = isConnected.size();
        for(int i=0;i<n;i++){
            if(!visited[i] && isConnected[currentCity][i] ){
                visitCities(visited,isConnected,i);
            }
        }
    }
};
// @lc code=end

