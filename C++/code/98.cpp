#define MAX 100000000000
#define MIN -100000000000

class Solution {
public:
    bool validate(TreeNode* cur, long long mini, long long maxi){
        if(!cur) return true;
        if(maxi <= cur->val || cur->val <= mini) return false;
        if(!validate(cur->left, mini, min(maxi, (long long)cur->val))) return false;
        if(!validate(cur->right, max(mini, (long long)cur->val), maxi)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return validate(root->left, MIN, root->val) && validate(root->right, root->val, MAX);
    }
};