/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
class Solution {
public:
    int count = 0;
    void dfs(int node,int parent, vector<vector<pair<int,int>>>& adjList){
        for(auto& [child,sign]: adjList[node]){
            if(child != parent){
                count += sign;
                dfs(child,node,adjList);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto& connection: connections){
            adjList[connection[0]].push_back({connection[1],1});
            adjList[connection[1]].push_back({connection[0],0});
        }
        dfs(0,-1,adjList);
        return count;
    }

};
// @lc code=end

