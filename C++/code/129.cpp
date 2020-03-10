class Solution {
    int ans = 0;
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        vector<int> empty;
        sumNumbers(root, empty);
        return ans;
    }
    void sumNumbers(TreeNode* root, vector<int> parents){
        if(!root->left && !root->right){
            parents.push_back(root->val);
            int num = 0;
            for(int i = 0;i < parents.size();i++){
                num += parents[i] * pow(10, (parents.size() - 1 - i));
            }
            ans += num;
            return;
        }
        parents.push_back(root->val);
        if(root->left) sumNumbers(root->left, parents);
        if(root->right) sumNumbers(root->right, parents);
    }
    
};