class Solution {
public:
    double record = 1e10;
    int ans = 0;
    void preorder(TreeNode* cur, double target){
        if(!cur) return;
        if(abs(target - cur->val) < record){
            record = abs(target - cur->val);
            ans = cur->val;
        }
        preorder(cur->left, target);
        preorder(cur->right, target);
    }
    int closestValue(TreeNode* root, double target) {
        preorder(root, target);
        return ans;
    }
};