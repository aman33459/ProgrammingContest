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
    //TreeNode* findr(int val , vector<int>& preorder , int left , int right);
    TreeNode* findl( vector<int>& preorder , int left , int right){
        //cout << left << " " << right << "++\n";
        if(left > right) return NULL; 
        TreeNode * tmp= new TreeNode();
        tmp->val=preorder[left];
        int ok=right+1;
        for(int i = left+1 ; i <= right ;i++){
            if(preorder[i] > preorder[left]) {
                ok=i;
                break;
            }
        }
        tmp->left = findl( preorder, left+1 , ok-1);
        tmp->right = findr(preorder , ok , right  );
        return tmp;
    }
    TreeNode* findr(vector<int>& preorder , int left , int right){
        if(left > right) return NULL; 
        TreeNode * tmp= new TreeNode();
        tmp->val=preorder[left];
        int ok=right+1;
        for(int i = left+1 ; i <=right ;i++){
            if(preorder[i] > preorder[left]) {
                ok=i;
                break;
            }
        }
        tmp->left = findl(preorder, left+1 , ok-1);
        tmp->right = findr(preorder , ok , right  );
        return tmp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root;
        TreeNode * tmp= new TreeNode();
        tmp->val=preorder[0];
        int ok=preorder.size();
        for(int i = 1 ; i < preorder.size();i++){
            if(preorder[i] > preorder[0]) {
                ok=i;
                break;
            }
        }
        tmp->left = findl( preorder, 1 , ok-1);
        tmp->right = findr( preorder , ok , preorder.size()-1  );
        return tmp;
    }
};
