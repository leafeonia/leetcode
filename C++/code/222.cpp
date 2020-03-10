class Solution {
    bool solved = false;
    int depth = 0;
    int cnt = 0;
public:
    void findDepth(TreeNode* root){
        while(root){
            root = root->left;
            depth++;
        }
    }
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* temp = root;
        findDepth(temp);
        solve(root, 1);
        return pow(2, depth) - cnt - 1;
    }
    
    void solve(TreeNode* root, int level){
        if(solved) return;
        if(level == depth){
            if(!root){
                cnt++;
                return;
            }
            else{
                solved = true;
                return;
            }
        }
        solve(root->right, level+1);
        solve(root->left, level+1);
    }
};