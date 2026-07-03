class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int index){
        if(index == word.size()) return true;
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) return false;
        char temp = board[r][c];
        board[r][c] = '#';  //mark visited
        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);
        board[r][c] = temp;  //backtracking
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0) return false;
        int r = board.size();
        int c = board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};
