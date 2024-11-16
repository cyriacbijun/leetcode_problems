/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {-1,0,1,0};
        map<pair<int,int>,int> timeElasped;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    timeElasped[{i,j}] = 0;
                }
                else if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int level = 0;
        while(!q.empty()){
            int qSize = q.size();
            level++;
            while(qSize--){
                auto ele = q.front();
                int r = ele.first;
                int c = ele.second;
                q.pop();
                for(int i=0;i<4;i++){
                    if(timeElasped.contains({r + dx[i],c + dy[i]}) && r + dx[i] >=0 && r + dx[i] < n && c + dy[i] >= 0 &&  c + dy[i] < m && timeElasped[{r + dx[i],c + dy[i]}] == 0){
                        timeElasped[{r + dx[i],c + dy[i]}] = level;
                        q.push({r + dx[i],c + dy[i]});
                    }
                }
            }
        }
        int maxtime = 0;
        for(auto& orange: timeElasped){
            if(orange.second == 0){
                return -1;
            }
            else if(orange.second > maxtime){
                maxtime = orange.second;
            }
        }
        return maxtime;
    }
};
// @lc code=end

