class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c){
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != 'O') return;
        board[r][c] = '#';
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        int r = board.size();
        int c = board[0].size();
        for(int i=0;i<r;i++){
            dfs(board,i,0);      // left boundary
            dfs(board,i,c-1);    // right boundary
        }
        for(int j=0;j<c;j++){
            dfs(board,0,j);      // top boundary
            dfs(board,r-1,j);    // bottom boundary
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
