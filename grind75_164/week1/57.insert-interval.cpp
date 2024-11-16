/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> sol;
        int i = 0, n = intervals.size();
        if(n == 0){
            sol.push_back(newInterval);
            return sol;
        }
        for(i;i<n; i++){
            if(intervals[i][1] < newInterval[0]){
                sol.push_back(intervals[i]);
            }
            else{
                break;
            }
        }
        while(i<n && intervals[i][0] <= newInterval[1]){
            newInterval = {  min(intervals[i][0],newInterval[0] ), max(newInterval[1], intervals[i][1])};
            i++;
        }
        sol.push_back(newInterval);
        for(i;i<n; i++){
            sol.push_back(intervals[i]);
        }
        return sol;
    }
};
// @lc code=end

