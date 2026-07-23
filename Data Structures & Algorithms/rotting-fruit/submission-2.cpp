class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& time, int i, int j, int currTime){
        int row = grid.size();
        int col = grid[0].size();
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0 || currTime >= time[i][j]){
            return;
        }
        time[i][j] = currTime;
        dfs(grid, time, i + 1, j, currTime + 1);
        dfs(grid, time, i - 1, j, currTime + 1);
        dfs(grid, time, i, j + 1, currTime + 1);
        dfs(grid, time, i, j - 1, currTime + 1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> time(row, vector<int>(col, INT_MAX));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 2) dfs(grid, time, i, j, 0);
            }
        }
        int timeReq = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                    if(time[i][j] == INT_MAX) return -1;
                    timeReq = max(timeReq, time[i][j]);
                }
            }
        }
        return timeReq;

    }
};
