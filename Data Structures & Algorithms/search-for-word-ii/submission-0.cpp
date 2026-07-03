class Solution {
public:
    class TrieNode {
    public:
        TrieNode* child[26];
        bool isWord;
        string word;
        TrieNode(){
            isWord = false;
            word = "";
            for(int i=0;i<26;i++) child[i] = NULL;
        }
    };
    TrieNode* buildTree(vector<string>& words){
        TrieNode* root = new TrieNode();
        for(string word : words){
            TrieNode* node = root;
            for(char ch : word){
                int index = ch - 'a';
                if(node -> child[index] == NULL){
                    node -> child[index] = new TrieNode();
                }
                node = node -> child[index];
            }
            node -> isWord = true;
            node -> word = word;
        }
        return root;
    }
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& ans){
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        char temp = board[r][c];
        if(temp == '#') return;
        if(node -> child[temp - 'a'] == NULL) return;
        node = node -> child[temp - 'a'];
        if(node -> isWord){
            ans.push_back(node -> word);
            node -> isWord = false;
        }
        board[r][c] = '#';
        dfs(board, r + 1 ,c, node, ans);
        dfs(board, r - 1, c, node, ans);
        dfs(board, r, c + 1, node, ans);
        dfs(board, r, c - 1, node, ans);
        board[r][c] = temp;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTree(words);
        vector<string> ans;
        int r = board.size();
        int c = board[0].size();
        for(int i=0;i<r;i++){
            for(int j = 0;j < c; j++){
                dfs(board, i, j, root, ans);
            }
        }
        return ans;
    }
};
