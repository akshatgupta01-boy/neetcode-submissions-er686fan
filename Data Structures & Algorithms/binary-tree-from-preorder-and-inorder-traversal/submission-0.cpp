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
    int findPos(vector<int> &inorder, int element, int n){
        for(int i = 0; i < n; i++){
            if(inorder[i] == element) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index, int inStart, int inEnd, int n){
        if(index >= n || inStart > inEnd){
            return NULL;
        }
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = findPos(inorder, element, n);
        root -> left = solve(preorder, inorder, index, inStart, position - 1, n);
        root -> right = solve(preorder, inorder, index, position + 1, inEnd, n);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        int n = inorder.size();
        TreeNode* ans = solve(preorder, inorder, preIndex, 0, n - 1, n);
        return ans;
    }
};
