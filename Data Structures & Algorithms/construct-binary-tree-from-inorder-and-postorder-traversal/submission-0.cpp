/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findPos(vector<int>& in, map<int, int>& mp, int n){
        for(int i=0;i<n;i++) mp[in[i]] = i;
    }
    TreeNode* solve(vector<int> in, vector<int> post, int &index, int inStart, int inEnd, int n, map<int, int> &mp){
        if(index < 0 || inStart > inEnd) return NULL;
        int ele = post[index--];
        TreeNode* root = new TreeNode(ele);
        int pos = mp[ele];
        root -> right = solve(in, post, index, pos + 1, inEnd, n, mp);
        root -> left = solve(in, post, index, inStart, pos - 1, n, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int, int> mp;
        int postIndex = n - 1;
        findPos(inorder, mp, n);
        TreeNode* ans = solve(inorder, postorder, postIndex, 0, n - 1, n, mp);
        return ans;
    }
};