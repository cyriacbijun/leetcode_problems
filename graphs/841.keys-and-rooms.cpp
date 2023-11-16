/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false) ;
        visited[0] = true;
        visitRooms(visited,rooms,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }

    void visitRooms(vector<bool>& visited,vector<vector<int>>& rooms,int currentEnteredRoom){
        int n = rooms[currentEnteredRoom].size();
        for(int i=0;i<n;i++){
            if(!visited[rooms[currentEnteredRoom][i]]){
                visited[rooms[currentEnteredRoom][i]] = true;
                visitRooms(visited,rooms,rooms[currentEnteredRoom][i]);
            }
        }
    }
};
// @lc code=end

