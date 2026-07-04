class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int r, int c){
        if(r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size()
        || vis[r][c]) return;
        vis[r][c] = true;
        //Up Direction
        if(r - 1 >= 0 && heights[r-1][c] >= heights[r][c]){
            dfs(heights, vis, r - 1, c);
        } 
        //Down Direction
        if(r + 1 < heights.size() && heights[r + 1][c] >= heights[r][c]){
            dfs(heights, vis, r + 1, c);
        } 
        //Left Direction
        if(c - 1 >= 0 && heights[r][c-1] >= heights[r][c]){
            dfs(heights, vis, r, c - 1);
        }
        //Right direction
        if(c + 1 < heights[0].size() && heights[r][c + 1] >= heights[r][c]){
            dfs(heights, vis, r, c + 1);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<bool>> pac(r, vector<bool>(c, false));
        vector<vector<bool>> atl(r, vector<bool>(c, false));
        //Pacific
        for(int i=0;i<r;i++){
            dfs(heights, pac, i, 0);
        }
        for(int j=0;j<c;j++){
            dfs(heights, pac, 0, j);  
        }
        //Atlantic
        for(int i=0;i<r;i++){
            dfs(heights, atl, i, c - 1);
        }
        for(int j=0;j<c;j++){
            dfs(heights, atl, r - 1, j);
        }
        vector<vector<int>> ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(pac[i][j] && atl[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
