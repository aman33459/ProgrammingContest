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
    int depth[200005];
    int par[200005];
    void dfs(TreeNode* root , int lvl , int pr){
        if(root == NULL) return;
        par[root->val] = pr;
        depth[root->val]=lvl;
        dfs(root->left , lvl+1,root->val);
        dfs(root->right , lvl+1 , root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root  , 0 , -1);
        if(par[x]!=par[y] && depth[x] == depth[y]) return true;
        else return false;
    }
};

