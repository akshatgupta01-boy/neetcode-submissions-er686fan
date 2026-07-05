class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty()) return;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0) q.push({i ,j});
            }
        }
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(auto d : dir){
                int nr = r + d.first;
                int nc = c + d.second;
                if(nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] != 2147483647) continue;
                grid[nr][nc] = 1 + grid[r][c];
                q.push({nr, nc});
            }
        }
    }
};
